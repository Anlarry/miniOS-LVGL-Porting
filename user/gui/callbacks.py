callbacks = 30
callbacks_h = "callbacks.h"
callbacks_c = "callbacks.c"


CallBack_C_Body =  '''
#include <stdint.h>
#include <ipc/ipc.h>
#include <gui/lvgl/lvgl.h>

#include "{header}"

int _call_back_num = 0;
int _max_call_back = {max};


uint32_t _Handler[{number}];
uint32_t _Test[{number}];
uint32_t _dst[{number}];

{{code}}

void* CallBackTable[] = {{{{

{{callback}} 

}}}};


'''.format(header = callbacks_h, max=callbacks,number = callbacks)

CallBack_H_Body = '''
#ifndef CALLBACK_H
#define CALLBACK_H

#include <stdint.h>

extern int _call_back_num;
extern int _max_call_back;

extern uint32_t _Handler[{number}];
extern uint32_t _Test[{number}];
extern uint32_t _dst[{number}];

extern void* CallBackTable[{number}];

#endif
'''.format(number = callbacks)

callback_fun = '''
void CallBack_{id}(lv_obj_t * obj, lv_event_t event)
{{
    IPC_MSG sig_test = {{
        .src = -1,
        .dst = _dst[{id}],
        .type = Signal,
        .data = {{SIG_SEND, _Handler[{id}], _Test[{id}]}}
    }}; 
    // send(&sig_test);
    
    switch(event) {{
        case LV_EVENT_CLICKED : 
            send(&sig_test);    
            break;
        case LV_EVENT_VALUE_CHANGED: 
            break;
    }}
}}

'''


if __name__ == "__main__":
    codes = ""
    callback_table = ",\n".join(["CallBack_{}".format(i) for i in range(callbacks)])
    for i in range(callbacks) : 
        codes += callback_fun.format(id = i)
    with open(callbacks_c, "w") as F:
        print(CallBack_C_Body.format(code = codes, callback = callback_table), file=F)
    with open(callbacks_h, "w") as F:
        print(CallBack_H_Body, file=F)

