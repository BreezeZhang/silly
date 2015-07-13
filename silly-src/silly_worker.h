#ifndef _SILLY_WORKER_H
#define _SILLY_WORKER_H

#include "silly_message.h"

struct silly_worker;
typedef struct lua_State lua_State;

struct silly_worker *silly_worker_create(int workid);
void silly_worker_free(struct silly_worker *w);

int silly_worker_push(struct silly_worker *w, struct silly_message *msg);

int silly_worker_start(struct silly_worker *w);
int silly_worker_dispatch(struct silly_worker *w);

void silly_worker_register(struct silly_worker *w, enum silly_message_type type, void (*cb)(lua_State *L, void *msg));

#endif
