#include <ipc/signal.h>

void Handler(Sigaction sigaction) {
    void (*_fun)();
    _fun = (void (*)())sigaction.handler;
    _fun();
    IPC_MSG sig_return = {
        .src = -1,
        .dst = -1,
        .type = Signal,
        .data = {SIG_RETURN}
    };
    send(&sig_return);
}