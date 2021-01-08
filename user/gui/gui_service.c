//
// Created by wang_shuai on 2021/1/5.
//
// GUI service to help other process create avaliable graphics

#include "stdio.h"
#include <gui/gui.h>
#include "./lvgl/lvgl.h"
#include <ipc/ipc.h>

static uint32_t buf[LV_HOR_RES_MAX * LV_VER_RES_MAX / 10]; /*Declare a buffer for 1/10 screen size*/
static uint32_t touchpad_x;
static uint32_t touchpad_y;

void static itoa(char str[], int num)/* 数字前面的 0 不被显示出来, 比如 0000B800 被显示成 B800 */
{
    char buf[100];
    int i, j;
    if(num == 0) {
        str[0] = '0';
        str[1] = 0;
        return ;
    }
    for(i = 0; num; num /= 10, i++) {
        buf[i] = num % 10;
    }
    for(j = 0, i = i-1; i >= 0; j++, i--) {
        str[j] = buf[i] + '0';
    }
    str[j] = 0;

}

static void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    printf("()");
    // static uint32_t flush_buf[LV_HOR_RES_MAX * LV_VER_RES_MAX / 10];
    // for(int i = area->x1 , k = 0;i <= area->x2; i++) {
    //     for(int j = - area->y1; j <= area->y2; j++) {
    //         flush_buf[k++] = color_p->full;
    //     }
    // }
    struct ROI roi = {
        .x1 = area->x1,
        .x2 = area->x2,
        .y1 = area->y1,
        .y2 = area->y2,
        .color = (Color *)color_p};
    GraphFlush(&roi);
    lv_disp_flush_ready(disp); /* Indicate you are ready with the flushing*/
}

bool my_input_read(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    data->point.x = touchpad_x;
    data->point.y = touchpad_y;
    data->state = LV_INDEV_STATE_PR ; //or LV_INDEV_STATE_REL;
    return false; /*No buffering now so no more data read*/
}

void main(int arg, char *argv[])
{
    int stdin = open("dev_tty0", O_RDWR);
    int stdout = open("dev_tty0", O_RDWR);
    int stderr = open("dev_tty0", O_RDWR);

    printf("o");

    InitLvFontMontserrat_14();
    lv_init();

    static lv_disp_buf_t disp_buf;
    lv_disp_buf_init(&disp_buf, buf, NULL, LV_HOR_RES_MAX * LV_VER_RES_MAX / 10);

    /* Register disp*/
    lv_disp_drv_t disp_drv;            /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);       /*Basic initialization*/
    disp_drv.flush_cb = my_disp_flush; /*Set your driver function*/
    disp_drv.buffer = &disp_buf;       /*Assign the buffer to the display*/
    lv_disp_drv_register(&disp_drv);   /*Finally register the driver*/

    /* Register Input */
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);      /*Basic initialization*/
    // indev_drv.type =...                 /*See below.*/
    // indev_drv.read_cb =...              /*See below.*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_input_read;
    
    lv_indev_t * mouse_indev = lv_indev_drv_register(&indev_drv);

    LV_IMG_DECLARE(my_img_dsc);                          /*Declare the image file.*/
    lv_obj_t * cursor_obj =  lv_img_create(lv_scr_act(), NULL); /*Create an image object for the cursor */
    lv_img_set_src(cursor_obj, &my_img_dsc);             /*Set the image source*/
    lv_indev_set_cursor(mouse_indev, cursor_obj);          

    // lv_indev_t * my_indev = lv_indev_drv_register(&indev_drv);
    
 
    //  ----------------------------------------------------------------------------

    lv_obj_t * label;
    lv_obj_t * label2;
    lv_obj_t *win = lv_win_create(lv_scr_act(), NULL);
    lv_win_set_title(win, "Window title");

    lv_obj_t *btn1 = lv_btn_create(lv_scr_act(), NULL);
    label = lv_label_create(btn1, NULL);
    lv_label_set_text(label, "Button");

    lv_obj_t *btn2 = lv_btn_create(lv_scr_act(), NULL);
    label2 = lv_label_create(btn2, NULL);
    lv_label_set_text(label2, "Button2");

    lv_obj_set_x(btn1, 50);
    lv_obj_set_y(btn1, 50);

    lv_obj_set_x(btn2, 50);
    lv_obj_set_y(btn2, 100);


    char buf_X[10];
    char buf_Y[10];
    IPC_MSG msg;
    while (1)
    {
        /* code */
        lv_tick_inc(1);

        int recv_code = recv(&msg);
        if (recv_code != SUCCESS)
        {
        }
        else
        {
            switch (msg.type)
            {
            case Button:
                break;
            case Window:
                break;
            case Keyboard:
                printf("%c", msg.data[0]);
                break;
            case Mouse:
                touchpad_x = msg.data[2];
                touchpad_y = msg.data[3];
                int pos = 0;
                itoa(buf_X,msg.data[2]);
                itoa(buf_Y,msg.data[3]);
                lv_label_set_text(label, buf_X);
                lv_label_set_text(label2, buf_Y);

                // lv_obj_set_x(btn1, touchpad_x);
                // lv_obj_set_y(btn1, touchpad_y);
                printf("(%d %d %d %d)", msg.data[0], msg.data[1], msg.data[2], msg.data[3]);
                break;
                
            }
        }
        lv_task_handler();
    }

    return;
}
