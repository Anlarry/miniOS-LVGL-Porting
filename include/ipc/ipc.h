#ifndef IPC_H
#define IPC_H 

#include <stdint.h>

#define MSG_SIZE 10

typedef struct IPC_MSG
{
    uint16_t src;
    uint16_t dst;
    uint32_t type;
    uint32_t data[MSG_SIZE];
}IPC_MSG;


/* type */
enum {
    /* gui type */
    Button,
    Window 


};


/* return */
enum {
    SUCCESS,
    FULL,
    EMPTY ,
    
};


int send(IPC_MSG *) ;
int recv(IPC_MSG *) ;

#endif 