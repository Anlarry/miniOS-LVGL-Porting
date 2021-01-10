API = {
    ('lv_obj_set_x', 2),
    ('lv_obj_set_y', 2),

    ('lv_btn_create',2),
    ('lv_textarea_create', 2),
    ('lv_label_create', 2),
    ('lv_win_create', 2)
}

Body = '''
#ifndef GUI_API_H
#define GUI_API_H

#include<ipc/ipc.h>
#include<gui/gui.h>

{}

#endif
'''

Code = '''

int {fun}({arg})
{{
    IPC_MSG msg = {{
        .src  = -1,
        .dst  = 4,
        .type = P2P, /* point 2 point */
        .data = {data}
    }};
    return send(&msg);
}}

'''

ServerCodeBody = '''
#ifndef GUI_SERVER_FUNCTION_H
#define GUI_SERVER_FUNCTION_H

#include <gui/gui.h>
#include "./lvgl/lvgl.h"
{}

#endif
'''

ServerCode = '''
void* FunctionTable[] = {{
    {}
}};
'''

def Args(x:int, pre:str) -> str :
    res = "{} {{}},".format(pre) * x
    res = res[:-1]
    args_names = ['arg_' + str(i) for i in range(x)] 
    return res.format(*args_names)

if __name__ == "__main__":
    codes = ""
    API = list(API)
    for i in range(len(API)):
        codes += Code.format(
            fun = API[i][0] + "_c",
            arg = Args(API[i][1], "int"),
            data = "{" + "{} /* type of data */, ".format("Function") 
                +"{} /* index of func */,".format(i) 
                + "{} /* # of Args */,".format(API[i][1]) 
                + Args(API[i][1], "") + "}"
        )
    with open("../../include/gui/api.h", 'w') as F:
        print(Body.format(codes), file=F)

    functions = ",\n".join([API[i][0] for i in range(len(API))])
    functions = ServerCode.format(functions)
    ServerCode = ServerCodeBody.format(functions)
    with open("function_table.h", "w") as F:
        print(ServerCode, file=F)  