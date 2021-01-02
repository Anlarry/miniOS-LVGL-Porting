#include <gui/gui.h>

void PlotPixel(int x, int y, int color) {
    uint8_t *p = Coor2Addr(x, y);
    *p = color & 0xf;
}

void PlotAddr(int addr, int color) {
    uint8_t *p = addr;
    *p = color & 0xf;
}

int Coor2Addr(int x, int y){
    return VRAM_START + x + y * SCRNX;
}

