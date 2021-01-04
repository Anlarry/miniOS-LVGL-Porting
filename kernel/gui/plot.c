#include "gui.h"

int static inline Coor2Addr(int x, int y){
    return (x + y * SCRNX) * 3;
}

void inline PlotPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
    uint8_t *p = Coor2Addr(x, y);
    __asm__ (
        "mov %1, %%fs:(%%edi)\n"
        "inc %0\n"
        "mov %2, %%fs:(%%edi)\n"
        "inc %0\n"
        "mov %3, %%fs:(%%edi)\n"
        : 
        : "D"(p), "r"(r), "r"(g), "r"(b)
        : 
    );
}

void inline PlotAddr(int addr, uint8_t color) {
    __asm__ (
        "mov %1, %%fs:(%%edi)\n"
        : 
        : "D"(addr), "r"(color)
        : 
    );
}


