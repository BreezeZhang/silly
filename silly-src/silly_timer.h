#ifndef _TIMER_H
#define _TIMER_H

#include <stdint.h>

int timer_init();
void timer_exit();
int timer_add(int time, int workid, uint64_t session);
uint32_t timer_now();
int timer_dispatch();


#endif


