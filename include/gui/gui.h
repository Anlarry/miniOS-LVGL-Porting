#ifndef GUI_H
#define GUI_H

#include "gtype.h"

#define VRAM_START 0xA0000
#define VRAM_END   0xB0000
#define SCRNX 320
#define SCRNY 200

#define Black              0                       
#define Blue               1                        
#define Green              2                        
#define Cyan               3        
#define Red                4                       
#define Magenta            5                        
#define Brown              6                        
#define Light_Gray         7                        
#define Dark_Gray          8                        
#define Light_Blue         9                        
#define Light_Green        10                       
#define Light_Cyan         11                       
#define Light_Red          12                       
#define Light_Magenta      13                       
#define Yellow             14                       
#define White              15                         

void InitScreen();

void PlotPixel(int x, int y, int color);
void PlotAddr(int addr, int color);

#endif
