/*
 * Automatically generated from raft.rpc
 */

#ifndef _RAFT_RPC_
#define _RAFT_RPC_

#include <event2/util.h> /* for ev_uint*_t */
#include <event2/rpc.h>

struct request_vote_request;
struct request_vote_response;
struct entry;
struct append_entries_request;
struct append_entries_response;

/* Tag definition for request_vote_request */
enum request_vote_request_ {
  REQUEST_VOTE_REQUEST_TERM=1,
  REQUEST_VOTE_REQUEST_CANDIDATE_ID=2,
  REQUEST_VOTE_REQUEST_LAST_LOG_INDEX=3,
  REQUEST_VOTE_REQUEST_LAST_LOG_TERM=4,
  REQUEST_VOTE_REQUEST_MAX_TAGS
};

/* Structure declaration for request_vote_request */
struct request_vote_request_access_ {
  int (*term_assign)(struct request_vote_request *, const ev_uint64_t);
  int (*term_get)(struct request_vote_request *, ev_uint64_t *);
  int (*candidate_id_assign)(struct request_vote_request *, const char *);
  int (*candidate_id_get)(struct request_vote_request *, char * *);
  int (*last_log_index_assign)(struct request_vote_request *, const ev_uint64_t);
  int (*last_log_index_get)(struct request_vote_request *, ev_uint64_t *);
  int (*last_log_term_assign)(struct request_vote_request *, const ev_uint64_t);
  int (*last_log_term_get)(struct request_vote_request *, ev_uint64_t *);
};

struct request_vote_request {
  struct request_vote_request_access_ *base;

  ev_uint64_t term_data;
  char *candidate_id_data;
  ev_uint64_t last_log_index_data;
  ev_uint64_t last_log_term_data;

  ev_uint8_t term_set;
  ev_uint8_t candidate_id_set;
  ev_uint8_t last_log_index_set;
  ev_uint8_t last_log_term_set;
};

struct request_vote_request *request_vote_request_new(void);
struct request_vote_request *request_vote_request_new_with_arg(void *);
void request_vote_request_free(struct request_vote_request *);
void request_vote_request_clear(struct request_vote_request *);
void request_vote_request_marshal(struct evbuffer *, const struct request_vote_request *);
int request_vote_request_unmarshal(struct request_vote_request *, struct evbuffer *);
int request_vote_request_complete(struct request_vote_request *);
void evtag_marshal_request_vote_request(struct evbuffer *, ev_uint32_t,
    const struct request_vote_request *);
int evtag_unmarshal_request_vote_request(struct evbuffer *, ev_uint32_t,
    struct request_vote_request *);
int request_vote_request_term_assign(struct request_vote_request *, const ev_uint64_t);
int request_vote_request_term_get(struct request_vote_request *, ev_uint64_t *);
int request_vote_request_candidate_id_assign(struct request_vote_request *, const char *);
int request_vote_request_candidate_id_get(struct request_vote_request *, char * *);
int request_vote_request_last_log_index_assign(struct request_vote_request *, const ev_uint64_t);
int request_vote_request_last_log_index_get(struct request_vote_request *, ev_uint64_t *);
int request_vote_request_last_log_term_assign(struct request_vote_request *, const ev_uint64_t);
int request_vote_request_last_log_term_get(struct request_vote_request *, ev_uint64_t *);
/* --- request_vote_request done --- */

/* Tag definition for request_vote_response */
enum request_vote_response_ {
  REQUEST_VOTE_RESPONSE_TERM=1,
  REQUEST_VOTE_RESPONSE_VOTE_GRANTED=2,
  REQUEST_VOTE_RESPONSE_MAX_TAGS
};

/* Structure declaration for request_vote_response */
struct request_vote_response_access_ {
  int (*term_assign)(struct request_vote_response *, const ev_uint64_t);
  int (*term_get)(struct request_vote_response *, ev_uint64_t *);
  int (*vote_granted_assign)(struct request_vote_response *, const ev_uint32_t);
  int (*vote_granted_get)(struct request_vote_response *, ev_uint32_t *);
};

struct request_vote_response {
  struct request_vote_response_access_ *base;

  ev_uint64_t term_data;
  ev_uint32_t vote_granted_data;

  ev_uint8_t term_set;
  ev_uint8_t vote_granted_set;
};

struct request_vote_response *request_vote_response_new(void);
struct request_vote_response *request_vote_response_new_with_arg(void *);
void request_vote_response_free(struct request_vote_response *);
void request_vote_response_clear(struct request_vote_response *);
void request_vote_response_marshal(struct evbuffer *, const struct request_vote_response *);
int request_vote_response_unmarshal(struct request_vote_response *, struct evbuffer *);
int request_vote_response_complete(struct request_vote_response *);
void evtag_marshal_request_vote_response(struct evbuffer *, ev_uint32_t,
    const struct request_vote_response *);
int evtag_unmarshal_request_vote_response(struct evbuffer *, ev_uint32_t,
    struct request_vote_response *);
int request_vote_response_term_assign(struct request_vote_response *, const ev_uint64_t);
int request_vote_response_term_get(struct request_vote_response *, ev_uint64_t *);
int request_vote_response_vote_granted_assign(struct request_vote_response *, const ev_uint32_t);
int request_vote_response_vote_granted_get(struct request_vote_response *, ev_uint32_t *);
/* --- request_vote_response done --- */

/* Tag definition for entry */
enum entry_ {
  ENTRY_INDEX=1,
  ENTRY_COMMAND=2,
  ENTRY_MAX_TAGS
};

/* Structure declaration for entry */
struct entry_access_ {
  int (*index_assign)(struct entry *, const ev_uint64_t);
  int (*index_get)(struct entry *, ev_uint64_t *);
  int (*command_assign)(struct entry *, const char *);
  int (*command_get)(struct entry *, char * *);
};

struct entry {
  struct entry_access_ *base;

  ev_uint64_t index_data;
  char *command_data;

  ev_uint8_t index_set;
  ev_uint8_t command_set;
};

struct entry *entry_new(void);
struct entry *entry_new_with_arg(void *);
void entry_free(struct entry *);
void entry_clear(struct entry *);
void entry_marshal(struct evbuffer *, const struct entry *);
int entry_unmarshal(struct entry *, struct evbuffer *);
int entry_complete(struct entry *);
void evtag_marshal_entry(struct evbuffer *, ev_uint32_t,
    const struct entry *);
int evtag_unmarshal_entry(struct evbuffer *, ev_uint32_t,
    struct entry *);
int entry_index_assign(struct entry *, const ev_uint64_t);
int entry_index_get(struct entry *, ev_uint64_t *);
int entry_command_assign(struct entry *, const char *);
int entry_command_get(struct entry *, char * *);
/* --- entry done --- */

/* Tag definition for append_entries_request */
enum append_entries_request_ {
  APPEND_ENTRIES_REQUEST_TERM=1,
  APPEND_ENTRIES_REQUEST_LEADER_ID=2,
  APPEND_ENTRIES_REQUEST_PREV_LOG_INDEX=3,
  APPEND_ENTRIES_REQUEST_PREV_LOG_TERM=4,
  APPEND_ENTRIES_REQUEST_ENTRIES=5,
  APPEND_ENTRIES_REQUEST_LEADER_COMMIT=6,
  APPEND_ENTRIES_REQUEST_MAX_TAGS
};

/* Structure declaration for append_entries_request */
struct append_entries_request_access_ {
  int (*term_assign)(struct append_entries_request *, const ev_uint64_t);
  int (*term_get)(struct append_entries_request *, ev_uint64_t *);
  int (*leader_id_assign)(struct append_entries_request *, const ev_uint64_t);
  int (*leader_id_get)(struct append_entries_request *, ev_uint64_t *);
  int (*prev_log_index_assign)(struct append_entries_request *, const ev_uint64_t);
  int (*prev_log_index_get)(struct append_entries_request *, ev_uint64_t *);
  int (*prev_log_term_assign)(struct append_entries_request *, const ev_uint64_t);
  int (*prev_log_term_get)(struct append_entries_request *, ev_uint64_t *);
  int (*entries_assign)(struct append_entries_request *, int, const struct entry*);
  int (*entries_get)(struct append_entries_request *, int, struct entry* *);
  struct entry*  (*entries_add)(struct append_entries_request *msg);
  int (*leader_commit_assign)(struct append_entries_request *, const ev_uint64_t);
  int (*leader_commit_get)(struct append_entries_request *, ev_uint64_t *);
};

struct append_entries_request {
  struct append_entries_request_access_ *base;

  ev_uint64_t term_data;
  ev_uint64_t leader_id_data;
  ev_uint64_t prev_log_index_data;
  ev_uint64_t prev_log_term_data;
  struct entry* *entries_data;
  int entries_length;
  int entries_num_allocated;
  ev_uint64_t leader_commit_data;

  ev_uint8_t term_set;
  ev_uint8_t leader_id_set;
  ev_uint8_t prev_log_index_set;
  ev_uint8_t prev_log_term_set;
  ev_uint8_t entries_set;
  ev_uint8_t leader_commit_set;
};

struct append_entries_request *append_entries_request_new(void);
struct append_entries_request *append_entries_request_new_with_arg(void *);
void append_entries_request_free(struct append_entries_request *);
void append_entries_request_clear(struct append_entries_request *);
void append_entries_request_marshal(struct evbuffer *, const struct append_entries_request *);
int append_entries_request_unmarshal(struct append_entries_request *, struct evbuffer *);
int append_entries_request_complete(struct append_entries_request *);
void evtag_marshal_append_entries_request(struct evbuffer *, ev_uint32_t,
    const struct append_entries_request *);
int evtag_unmarshal_append_entries_request(struct evbuffer *, ev_uint32_t,
    struct append_entries_request *);
int append_entries_request_term_assign(struct append_entries_request *, const ev_uint64_t);
int append_entries_request_term_get(struct append_entries_request *, ev_uint64_t *);
int append_entries_request_leader_id_assign(struct append_entries_request *, const ev_uint64_t);
int append_entries_request_leader_id_get(struct append_entries_request *, ev_uint64_t *);
int append_entries_request_prev_log_index_assign(struct append_entries_request *, const ev_uint64_t);
int append_entries_request_prev_log_index_get(struct append_entries_request *, ev_uint64_t *);
int append_entries_request_prev_log_term_assign(struct append_entries_request *, const ev_uint64_t);
int append_entries_request_prev_log_term_get(struct append_entries_request *, ev_uint64_t *);
int append_entries_request_entries_assign(struct append_entries_request *, int, const struct entry*);
int append_entries_request_entries_get(struct append_entries_request *, int, struct entry* *);
struct entry*  append_entries_request_entries_add(struct append_entries_request *msg);
int append_entries_request_leader_commit_assign(struct append_entries_request *, const ev_uint64_t);
int append_entries_request_leader_commit_get(struct append_entries_request *, ev_uint64_t *);
/* --- append_entries_request done --- */

/* Tag definition for append_entries_response */
enum append_entries_response_ {
  APPEND_ENTRIES_RESPONSE_TERM=1,
  APPEND_ENTRIES_RESPONSE_SUCCESS=2,
  APPEND_ENTRIES_RESPONSE_MAX_TAGS
};

/* Structure declaration for append_entries_response */
struct append_entries_response_access_ {
  int (*term_assign)(struct append_entries_response *, const ev_uint64_t);
  int (*term_get)(struct append_entries_response *, ev_uint64_t *);
  int (*success_assign)(struct append_entries_response *, const ev_uint32_t);
  int (*success_get)(struct append_entries_response *, ev_uint32_t *);
};

struct append_entries_response {
  struct append_entries_response_access_ *base;

  ev_uint64_t term_data;
  ev_uint32_t success_data;

  ev_uint8_t term_set;
  ev_uint8_t success_set;
};

struct append_entries_response *append_entries_response_new(void);
struct append_entries_response *append_entries_response_new_with_arg(void *);
void append_entries_response_free(struct append_entries_response *);
void append_entries_response_clear(struct append_entries_response *);
void append_entries_response_marshal(struct evbuffer *, const struct append_entries_response *);
int append_entries_response_unmarshal(struct append_entries_response *, struct evbuffer *);
int append_entries_response_complete(struct append_entries_response *);
void evtag_marshal_append_entries_response(struct evbuffer *, ev_uint32_t,
    const struct append_entries_response *);
int evtag_unmarshal_append_entries_response(struct evbuffer *, ev_uint32_t,
    struct append_entries_response *);
int append_entries_response_term_assign(struct append_entries_response *, const ev_uint64_t);
int append_entries_response_term_get(struct append_entries_response *, ev_uint64_t *);
int append_entries_response_success_assign(struct append_entries_response *, const ev_uint32_t);
int append_entries_response_success_get(struct append_entries_response *, ev_uint32_t *);
/* --- append_entries_response done --- */

#endif  /* _RAFT_RPC_ */
