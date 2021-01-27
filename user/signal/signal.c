#include <signal/signal.h>
#include <stddef.h>
#include <stdarg.h>

void Handler(Sigaction sigaction) {
    void (*_fun)(int, int);
    _fun = (void (*)(int, int))sigaction.handler;
    _fun(sigaction.sig, sigaction.arg);
    int ebp;
    __asm__ __volatile__ (
        "mov %%ebp, %0"
        : "=r"(ebp)
        : 
        :
    );
    sigreturn(ebp);
}

int kill(int pid, int sig, ...) {
    va_list ap = (va_list)((char*)(&sig) + 4);
    Sigaction sigaction = {
        .sig = sig,
        .handler = NULL,
        
        .arg = *((uint32_t*)ap)
    };
    // if((arg = va_arg(ap, int)) != -1) {
    //     sigaction.extra_arg = true;
    //     sigaction.arg = arg;
    // }
    return sigsend(pid, &sigaction);
}

int signal(int sig, void* handler) {
    return __signal(sig, handler, HANDLER);
}