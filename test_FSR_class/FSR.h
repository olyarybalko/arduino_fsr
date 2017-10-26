/*
  FSR.cpp - Library for communicate via TWI 
  with slave uC with FSR sensors.
  Created by Olga Melnyk, September 25, 2017.
  Released into the public domain.
*/

#ifndef FSR_h
#define FSR_h

#include "Arduino.h"
#include <Wire.h>
class FSR
{
  private:
    int     _address;
    int     _pin;
    double  _a;
    double  _b;
    double  _c;
    double  _d;
  public:
    FSR (int address, int pin,  double a, double b, double c, double d);// constructor uses addresse of slave uC
    // si en cours de lexecution il faut changer la broche
    void    set_i2c_pin(int);
    // si en cours d'execution il fqut changer le coeficient en fonction de temperature
    void    set_coef_a(double);
    void    set_coef_b(double);
    void    set_coef_c(double);
    void    set_coef_d(double);
    double  get_coef_a(void);
    double  get_coef_b(void);
    double  get_coef_c(void);
    double  get_coef_d(void);
    double  get_force();
  
    
};

#endif
