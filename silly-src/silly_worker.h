#ifndef _SILLY_WORKER_H
#define _SILLY_WORKER_H

#include "silly_message.h"

struct silly_worker;
struct lua_State;
struct silly_config;

struct silly_worker *silly_worker_create(int workid);
void silly_worker_free(struct silly_worker *w);

int silly_worker_getid(struct silly_worker *w);

int silly_worker_push(struct silly_worker *w, struct silly_message *msg);

int silly_worker_start(struct silly_worker *w, const struct silly_config *config);
void silly_worker_stop(struct silly_worker *w);

int silly_worker_dispatch(struct silly_worker *w);

void silly_worker_message(struct silly_worker *w, void (*msg)(struct lua_State *L, struct silly_message *msg));

void silly_worker_exit(struct silly_worker *w, void (*exit)(struct lua_State *L));

#endif

