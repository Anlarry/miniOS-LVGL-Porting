#ifndef IPC_H
#define IPC_H 

#include <stdint.h>

#define MSG_SIZE 10

#define MSG_BUF_SIZE 100

typedef struct IPC_MSG
{
    uint16_t src;
    uint16_t dst;
    uint32_t type;
    uint32_t data[MSG_SIZE];
}IPC_MSG;


/* type */
enum Type{
    /* gui support widget type */
    Button,
    Window,

    /* signal relevant  functions type*/
    Signal_Send,
    Signal_Return,


    /*gui input required mass*/
    Keyboard,
    Mouse,

    /* Request */
};


/* return */
enum MsgReturn{
    SUCCESS,
    FULL,
    EMPTY ,
};


int send(IPC_MSG *) ;
int recv(IPC_MSG *) ;

#endif 