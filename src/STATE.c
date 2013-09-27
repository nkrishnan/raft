
#include <event.h>
#include <stdlib.h>
#include <string.h>
#include "params.h"
#include "STATE.h"

extern void election_cb(evutil_socket_t fd, short event, void * arg);

int identity_cmp(struct IDENTITY const *l, struct IDENTITY const *r) {
  int hostcmp_res = strcmp(l->host, r->host);
  int portcmp_res = (l->port == r->port) ? 0 : (l->port < r->port) ? -1 : 1;
  if(hostcmp_res == 0 && portcmp_res == 0) return 0;
  if(hostcmp_res) return hostcmp_res;
  return portcmp_res;
}

void reset_leader_state(struct STATE * s) {
}

struct PERSISTENT_STATE {
  uint64_t current_term;
  struct IDENTITY * voted_for;
};

struct STATE {
  struct PERSISTENT_STATE persistent_state;
  struct IDENTITY * others;
  uint64_t commit_index;
  uint64_t last_applied;
  enum Role role;
  struct IDENTITY * self_id;
  struct event * election_event;
  struct timeval election_timeout;
};

struct STATE * init_state(struct event_base *eb) {
  struct STATE * s = calloc(1, sizeof(struct STATE));
  reset_leader_state(s);
  s->role = Follower;
  s->election_event = calloc(1, sizeof(struct event));
  evtimer_set(s->election_event, election_cb, s);
  event_base_set(eb, s->election_event);
  s->election_timeout.tv_sec = ELECTION_TIMEOUT;
  s->election_timeout.tv_usec = 0;
  evtimer_add(s->election_event, &s->election_timeout);
}

uint64_t get_term(struct STATE * s) {
  return s->persistent_state.current_term;
}

uint64_t increment_term(struct STATE *s) {
  s->persistent_state.current_term += 1;
  return s->persistent_state.current_term;
}

enum Role get_role(struct STATE *s) {
  return s->role;
}

enum Role set_role(struct STATE *s, enum Role r) {
  s->role = r;
  return s->role;
}

struct IDENTITY * get_self_id(struct STATE * s) {
  return s->self_id;
}
