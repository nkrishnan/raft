
#include <event.h>

enum { MAX_HOST_NAME_LEN = 256 };
enum Role { Follower, Candidate, Leader };

struct LEADER_STATE {
  uint64_t * next_index;
  uint64_t * match_index;
};

void reset_leader_state(struct LEADER_STATE *);

struct PERSISTENT_STATE {
  uint64_t current_term;
  char voted_for[MAX_HOST_NAME_LEN];
};

struct STATE {
  struct PERSISTENT_STATE persistent_state;
  struct LEADER_STATE leader_state;
  uint64_t commit_index;
  uint64_t last_applied;
  Role role;
  struct event * election_event;
  struct timeval election_timeout;
};

struct STATE * init_state();
