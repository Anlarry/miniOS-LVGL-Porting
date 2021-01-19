#include <signal/signal.h>
#include <stddef.h>

void Handler(Sigaction sigaction) {
    void (*_fun)();
    _fun = (void (*)())sigaction.handler;
    _fun();
    int ebp;
    __asm__ __volatile__ (
        "mov %%ebp, %0"
        : "=r"(ebp)
        : 
        :
    );
    sigreturn(ebp);
}

int kill(int pid, int sig) {
    Sigaction sigaction = {
        .sig = sig,
        .handler = NULL,
        ._Handler = HANDLER
    };
    return sigsend(pid, &sigaction);
}