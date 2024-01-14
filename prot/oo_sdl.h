#ifndef OO_PROT_WINDOWS_SDL_H_
#define OO_PROT_WINDOWS_SDL_H_
/* Includes ------------------------------------------------------------------*/
#include <SDL2/SDL.h>

#include "U8g2lib.h"
#include "oo_cfg.h"
#include "oo_display.h"
/* Define --------------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported typedef ----------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
class OO_DisplaySDL : public OO_UI {
public:
    bool exit;  // 是否退出
    explicit OO_DisplaySDL(U8G2 &u8g2) : OO_UI(u8g2) {}

    bool Init();
    // void Refresh(uint32_t tick);
    virtual InputEvent Scan();
    void Exit();
};
#endif  // OO_PROT_WINDOWS_SDL_H_
