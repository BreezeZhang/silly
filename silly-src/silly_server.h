#ifndef _SILLY_SERVER_H
#define _SILLY_SERVER_H

struct silly_message;
struct silly_config;

int silly_server_init();
int silly_server_exit();

int silly_server_open();

//for connect balance
int silly_server_balance(int workid, int sid);

int silly_server_push(int handle, struct silly_message *msg);

int silly_server_start(int handle, const struct silly_config *config);
void silly_server_stop(int handle);

int silly_server_dispatch(int handle);


#endif
