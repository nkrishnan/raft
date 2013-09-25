
#include <event.h>
#include <event2/buffer.h>
#include <event2/event.h>
#include <event2/event_compat.h>
#include <event2/http.h>
#include <event2/http_compat.h>
#include <event2/http_struct.h>
#include <event2/rpc.h>
#include <event2/tag.h>

#include <signal.h>

#include "rack.gen.h"
#include "rack_server.h"

EVRPC_HEADER(RequestVote, request_vote_request, request_vote_response)
EVRPC_GENERATE(RequestVote, request_vote_request, request_vote_response)

static void request_vote_cb(EVRPC_STRUCT(RequestVote)* rpc, void * arg) {
  /*
  struct request_vote_reply* rvr = rpc->reply;
  rvr->term = 1;
  rvr->vote_granted = 1;
  EVRPC_REQUEST_DONE(rpc);
  */
}

int main( int argc, char * argv[] ) {

  struct event_base * base = event_base_new();
  struct evhttp * http = evhttp_new(base);

  int port = 1979;
  char const * host = "127.0.0.1";
  evhttp_bind_socket_with_handle(http, host, port);

  signal(SIGPIPE, SIG_IGN);

  struct evrpc_base * rpc_base;
  rpc_base = evrpc_init(http);

  EVRPC_REGISTER(rpc_base, RequestVote, request_vote_request, request_vote_response, request_vote_cb, NULL);

  event_base_dispatch(base);
}
