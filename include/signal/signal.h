#ifndef SIGNAL_H
#define SIGNAL_H 

#include <stdint.h>

typedef struct Sigaction {
    int sig;
    void *handler;
    void *_Handler;
}Sigaction;

void Handler(Sigaction sigaction);

int kill(int pid, int sig);

#define HANDLER Handler

#endif