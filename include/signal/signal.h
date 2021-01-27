#ifndef SIGNAL_H
#define SIGNAL_H 

#include <stdint.h>
#include <stdbool.h>

typedef struct Sigaction {
    int sig;
    void *handler;

    uint32_t arg;
}Sigaction;

void Handler(Sigaction sigaction);

int kill(int pid, int sig, ...);

int signal(int sig, void* handler);

#define HANDLER Handler

#endif