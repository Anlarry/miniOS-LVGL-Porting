#ifndef SIGNAL_H
#define SIGNAL_H 

#include "ipc.h"

typedef struct Sigaction {
    void *handler;
}Sigaction;

void Handler(Sigaction sigaction);

#define HANDLER Handler

#endif