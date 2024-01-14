/* Includes ------------------------------------------------------------------*/
#include <SDL2/SDL.h>
#include <synchapi.h>

#include <iostream>

#include "oo_display.h"
#include "oo_sdl.h"
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
U8G2 oo_u8g2;
OO_DisplaySDL oo_display(oo_u8g2);
/* Private functions ---------------------------------------------------------*/

// TODO: 将前缀OO改为C++的命名空间

#undef main
int main(int argc, char *args[]) {
    const volatile uint8_t tick = 10;
    oo_display.Init();
    for (;;) {
        oo_display.Refresh(tick);
        oo_display.Scan();
        if(oo_display.exit) {
            break;
        }
        oo_display.IncTick(tick);
        Sleep(tick);
    }
    oo_display.Exit();
    return 0;
}