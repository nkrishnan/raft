
#include <event.h>
#include <event2/buffer.h>
#include <event2/event.h>
#include <event2/event_compat.h>
#include <event2/http.h>
#include <event2/http_compat.h>
#include <event2/http_struct.h>
#include <event2/rpc.h>
#include <event2/tag.h>

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

#include "rack.gen.h"
#include "STATE.h"

EVRPC_HEADER(RequestVote, request_vote_request, request_vote_response)
EVRPC_GENERATE(RequestVote, request_vote_request, request_vote_response)

void issue_request_vote(struct STATE * s) {
  struct IDENTITY * i = get_peer_ids(s);
  while(i) {
    struct request_vote_request * rvr = request_vote_request_new();
    EVTAG_ASSIGN(rvr, 
  }
}

void election_cb(evutil_socket_t fd, short event, void * arg) {
  struct STATE * s = (struct STATE *) arg;
  increment_term(s);
  set_role(s, Candidate);
  issue_request_vote(s);
}

static void request_vote_cb(EVRPC_STRUCT(RequestVote)* rpc, void * arg) {

  struct request_vote_response* rvr = rpc->reply;
  EVTAG_ASSIGN(rvr, term, 1);
  EVTAG_ASSIGN(rvr, vote_granted, 1);
  EVRPC_REQUEST_DONE(rpc);
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

  struct STATE * s = init_state(base);
  event_base_dispatch(base);
}
