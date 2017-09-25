/*
  FSR.cpp - Library for communicate via TWI 
  with slave uC with FSR sensors.
  Created by Olga Melnyk, September 25, 2017.
  Released into the public domain.
*/

#ifndef FSR_h
#define FSR_h

#include "Arduino.h"

class FSR
{
  public:
    FSR     (int pin);
    void    set_coef_a(double);
    void    set_coef_b(double);
    void    set_coef_c(double);
    void    set_coef_d(double);
    double  get_coef_a(void);
     double  get_coef_b(void);
      double  get_coef_c(void);
       double  get_coef_d(void);
       double FSR::get_force();
  private:
    int     _pin;
    double  _a;
    double  _b;
    double  _c;
    double  _d;
    
};

#endif
