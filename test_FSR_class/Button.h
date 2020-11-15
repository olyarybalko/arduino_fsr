#ifndef BUTTON_H
#define BUTTON_H
#include "Arduino.h"  //pour pouvoir utiliser les constantes ou des fonctions faisant parti du core d'Arduino
#include "Sensor.h" 
class Button : public Sensor {
  public:
    Button (int pin);
    bool is_pressed();
    bool is_avaible(); 
  private: 
    int _mode=0;
    int _state=0;
};
#endif
