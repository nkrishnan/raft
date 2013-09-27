
#ifndef _STATE_H_
#define _STATE_H_

#include <event.h>

enum { MAX_NAME_LEN = 256 };
enum Role { Follower, Candidate, Leader };

struct IDENTITY {
  char host[MAX_NAME_LEN];
  int port;
  uint64_t next_index;
  uint64_t match_index;
};

// establishes lexicographic ordering of IDENTITY structures
int identity_cmp(struct IDENTITY const *l, struct IDENTITY const *r);

struct STATE;

struct STATE * init_state(struct event_base *eb);

enum Role get_role(struct STATE *s);

enum Role set_role(struct STATE *s, enum Role r);

uint64_t get_term(struct STATE * s);

uint64_t increment_term(struct STATE *s);

void reset_leader_state(struct STATE * s);

struct IDENTITY * get_self_id(struct STATE * s);

struct IDENTITY * get_peer_ids(struct STATE *s);

uint64_t get_last_log_index(struct STATE * s);

uint64_t get_last_log_term(struct STATE * s);


#endif
