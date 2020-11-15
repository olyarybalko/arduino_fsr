#ifndef TACTILE_H
#define TACTILE_H
#include "Arduino.h"
#include "Actuator.h"

class Tactile : public Actuator {
  public:
    Tactile (int pin);
    void short_pulse();
    void long_pulse();
  private:
    int _mode=0;
    int _state=0;
};
#endif
