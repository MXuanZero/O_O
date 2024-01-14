#ifndef OO_SRC_OO_DISPLAY_H_
#define OO_SRC_OO_DISPLAY_H_
/* Includes ------------------------------------------------------------------*/
#include <cstdint>

#include "U8g2lib.h"
#include "oo_cfg.h"
/* Define --------------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported typedef ----------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
class OO_UI {
private:
    volatile uint32_t _tick = 0;

protected:
    int _w = OO_SCREEN_WIDTH;
    int _h = OO_SCREEN_HEIGHT;

public:
    typedef enum {
        EVENT_NONE = 0,
        EVENT_UP,
        EVENT_DOWN,
        EVENT_RIGHT,
        EVENT_LEFT,
        EVENT_ENTER,
        EVENT_CANCEL,
        EVENT_EXIT,
        EVENT_QUIT = 255,
    } InputEvent;

    U8G2 &_u8g2;
    explicit OO_UI(U8G2 &u8g2) : _u8g2(u8g2) {}

    virtual bool Init() = 0;
    virtual void Exit() = 0;
    virtual InputEvent Scan() = 0;

    void Refresh(uint32_t tick);
    void IncTick(uint32_t tick) { _tick += tick; }
    void SetTick(uint32_t tick) { _tick = tick; }
    uint32_t GetTick() const { return _tick; }
};

#endif  // OO_SRC_OO_DISPLAY_H_
