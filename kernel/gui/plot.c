#include "plot.h"
#include <protect.h>

 int Coor2Addr(int x, int y){
     return (x + y * SCRNX) * 3;
 }

// void inline PlotPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
//     uint8_t *p = Coor2Addr(x, y);
//     __asm__ (
//         "mov %1, %%fs:(%%edi)\n"
//         "inc %0\n"
//         "mov %2, %%fs:(%%edi)\n"
//         "inc %0\n"
//         "mov %3, %%fs:(%%edi)\n"
//         : 
//         : "D"(p), "r"(r), "r"(g), "r"(b)
//         : 
//     );
// }

 void inline PlotAddr(int addr, uint8_t color) {
     __asm__ (
         "mov %1, %%fs:(%%edi)\n"
         :
         : "D"(addr), "r"(color)
         :
     );
 }

static Timer = 100;
void sys_flush(ROI* roi)
{
    disable_int();
    int x1 = roi->x1;
    int y1 = roi->y1;
    int x2 = roi->x2;
    int y2 = roi->y2;

    uint32_t* color = roi->color;
    uint16_t fs = SELECTOR_GRAPH;
    uint16_t fs_old;

    static uint32_t kernel_buffer[SCRNY*SCRNX/10];

    uint32_t *p = (uint32_t*)kernel_buffer;
    for(int i = y1; i <= y2; i++) {
        for(int j = x1; j <= x2; j++) {
            *p++ = *color++;
        }
    }

    __asm__ __volatile__ (
        "mov %%fs, %0\n"
        : "=r"(fs_old)
        :
        :
    );
    __asm__ __volatile__ (
        "mov %%ax, %%fs\n"
        : 
        : "a"(fs)
        :
    );
    __asm__ __volatile__("mov %cr3, %eax");
    __asm__ __volatile__("push %eax");
    __asm__ __volatile__("mov $0x200000, %eax");
    __asm__ __volatile__("mov %eax, %cr3");

    //uint8_t *p = 0;
    Color *ptr = kernel_buffer;

    for(int i = y1; i <= y2; ++i) {
        for(int j = x1; j <= x2; ++j) {
            int p = Coor2Addr(j,i);
         __asm__ (
             "mov %1, %%fs:(%%edi)\n"
             "inc %0\n"
             "mov %2, %%fs:(%%edi)\n"
             "inc %0\n"
             "mov %3, %%fs:(%%edi)\n"
             :
             : "D"(p), "r"(ptr->blue), "r"(ptr->green), "r"(ptr->red)
             :
         );
         ptr++;
        }
    }



   __asm__ __volatile__("pop %eax");
   __asm__ __volatile__("mov %eax, %cr3");

    __asm__ __volatile__ (
        "mov %%ax, %%fs"
        : 
        : "a"(fs_old)
        :
    );

    enable_int();
}

