/* Includes ------------------------------------------------------------------*/
#include "oo_sdl.h"

#include <iostream>
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/*Private function prototypes -----------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
#ifndef NO_SDL
extern SDL_Window *u8g_sdl_window;
extern SDL_Surface *u8g_sdl_screen;
#endif
/* Private functions ---------------------------------------------------------*/
bool OO_DisplaySDL::Init() {
    u8g2_SetupBuffer_SDL_128x64(_u8g2.getU8g2(), &u8g2_cb_r0);

    _u8g2.initDisplay();
    _u8g2.setPowerSave(0);
    _u8g2.setFont(u8g2_font_helvB18_tr);

    return true;
}

void OO_DisplaySDL::Exit() {
    SDL_FreeSurface(u8g_sdl_screen);
    SDL_DestroyWindow(u8g_sdl_window);
    SDL_Quit();
    std::cout << "o_o quit!" << std::endl;
}

OO_UI::InputEvent OO_DisplaySDL::Scan() {
    int k = u8g_sdl_get_key();
    if (k == 'q' || k == SDL_QUIT) {
        exit = true;
        return OO_UI::EVENT_QUIT;
    }
    return OO_UI::EVENT_NONE;
}

/* other ---------------------------------------------------------------------*/