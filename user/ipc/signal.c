#include <ipc/signal.h>

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
    IPC_MSG sig_return = {
        .src = -1,
        .dst = -1,
        .type = Signal,
        .data = {SIG_RETURN, ebp}
    };
    
    send(&sig_return);
}