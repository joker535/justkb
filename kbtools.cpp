#include "kbtools.h"
#include "usbd_hid_composite_if.h"

Kbtools::Kbtools()
{
}

void Kbtools::begin(void)
{
  HID_Composite_Init(HID_KEYBOARD);
}

void Kbtools::end(void)
{
  HID_Composite_DeInit(HID_KEYBOARD);
}

void Kbtools::sendReport(KeyReport *keys)
{
  uint8_t buf[8] = {keys->modifiers, keys->reserved, keys->keys[0], keys->keys[1],
                    keys->keys[2], keys->keys[3], keys->keys[4], keys->keys[5]
                   };

  HID_Composite_keyboard_sendReport(buf, 8);

  //delay required to prevent persistent key when call print
  delay(20);
}

void Kbtools::record(void)
{
  _keyReport.modifiers = 0;
  _keyReport.reserved = 0;
  _index = 0;
}

void Kbtools::addKeyPress(uint8_t kc)
{
  if(kc>=KC_LCTRL && kc<=KC_RGUI)
  {
    
  }else
  {
     if (_keyReport.keys[0] != kc && _keyReport.keys[1] != kc &&
        _keyReport.keys[2] != kc && _keyReport.keys[3] != kc &&
        _keyReport.keys[4] != kc && _keyReport.keys[5] != kc) {
    
           _keyReport.keys[_index++] = kc;
           if (_index == 6) {
             //TODO error         
           }
     }
  }
}

void Kbtools::report(void)
{
  while(_index < 6)
  {
     _keyReport.keys[_index++] = 0;
  }
  sendReport(&_keyReport);
}
