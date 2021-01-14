/**
 * @file lv_demo_widgets.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "stdio.h"
#include "./lvgl/lvgl.h"
#include <gui/gui.h>
#include <ipc/ipc.h>
#include "./demo/lv_demo_music_main.h"
#include "./demo/lv_demo_widgets.h"
#include "./demo/lv_demo_printer.h"
#include "./demo/lv_demo_keypad_encoder.h"

// ---------------------------------------------------------------------------------------------

static uint32_t buf[LV_HOR_RES_MAX * LV_VER_RES_MAX / 10]; /*Declare a buffer for 1/10 screen size*/
static uint32_t touchpad_x;
static uint32_t touchpad_y;
static uint32_t left_pressed;
static uint32_t right_pressed;

#define MASK_RAW	0x01FF
#define FLAG_EXT	0x0100		/* Normal function keys		*/
#define ENTER		(0x03 + FLAG_EXT)	/* Enter	*/
#define BACKSPACE	(0x04 + FLAG_EXT)	/* BackSpace	*/

static void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
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
    data->state = left_pressed == 1 ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;

    return false; /*No buffering now so no more data read*/
}


static char last_k;
static char press;
bool keyboard_read(lv_indev_drv_t * drv, lv_indev_data_t*data){
    data->key = last_k;            /*Get the last pressed or released key*/
    data->state = LV_INDEV_STATE_PR;
    if(press) {
        data->state = LV_INDEV_STATE_PR;
        press = false;
    }
    else data->state = LV_INDEV_STATE_REL;

  return false; /*No buffering now so no more data read*/
}

int main(int arg, char *argv[])
{
    int stdin = open("dev_tty0", O_RDWR);
    int stdout = open("dev_tty0", O_RDWR);
    int stderr = open("dev_tty0", O_RDWR);

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

    /* Register Input MousePtr */
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);      /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_input_read;
    lv_indev_t * mouse_indev = lv_indev_drv_register(&indev_drv);

    LV_IMG_DECLARE(my_img_dsc);                          /*Declare the image file.*/
    lv_obj_t * cursor_obj =  lv_img_create(lv_scr_act(), NULL); /*Create an image object for the cursor */
    lv_img_set_src(cursor_obj, &my_img_dsc);             /*Set the image source*/
    lv_indev_set_cursor(mouse_indev, cursor_obj);    

    
    // lv_indev_drv_t kb_drv;
    // lv_indev_drv_init(&kb_drv);
    // kb_drv.type = LV_INDEV_TYPE_KEYPAD;
    // kb_drv.read_cb = keyboard_read;
    // lv_indev_t * kb_indev = lv_indev_drv_register(&kb_drv);
    // lv_indev_set_group(kb_indev, g);


    //lv_demo_widgets();
    //lv_demo_music();
    // lv_demo_printer();
    lv_demo_keypad_encoder();
    //  ----------------------------------------------------------------------------

    IPC_MSG msg;
    uint32_t ack_data;
    int tick_T = 0;
    while (1)
    {
        /* code */
        if(tick_T == 0) {
            lv_tick_inc(1);
        }
        tick_T = (tick_T + 1) % 20;


        int recv_code = recv(&msg);
        if (recv_code != SUCCESS)
        {
        }
        else
        {
            GUI *usr_data = (GUI*)(&msg.data);
            switch (usr_data->type)
            {
            // case Button:
            //     cur_btn = lv_btn_create(lv_scr_act(), NULL);
            //     lv_obj_set_x(cur_btn, usr_data->data[0]);
            //     lv_obj_set_y(cur_btn, usr_data->data[1]);
            //     ack_data = cur_btn;
            //     break;
            // case Window:
            //     break;
            case Keyboard:
                switch (usr_data->data[0] & MASK_RAW) {
                    case ENTER:
                        last_k = '\n';
                        break;
                    case BACKSPACE:
                        last_k = '\b';
                        break;
                    default :
                        last_k = usr_data->data[0];
                }
                press = true;
                // if(active_ta != NULL) {
                //     lv_textarea_add_char(active_ta, usr_data->data[0]);
                // }
                break;
            case Mouse:
                touchpad_x = usr_data->data[2];
                touchpad_y = usr_data->data[3];

                left_pressed = usr_data->data[0];

                break;

            }
        }

        lv_task_handler();
    }

    return;
}
