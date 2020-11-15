/*
  FSR.cpp - Library for communicate via TWI 
  with slave uC with FSR sensors.
  Created by Olga Melnyk, September 25, 2017.
  Released into the public domain.
*/
#ifndef FSR_H
#define FSR_H

#include "Arduino.h"
#include "Sensor.h"
class FSR : public Sensor
{
  private:
    double  _a;
    double  _b;
    double  _c;
    double  _d;
   
  public:

    FSR (int pin, double a, double b, double c, double d);
    
    // si en cours d'execution il fqut changer le coeficient en fonction de temperature
    
    bool is_avaible(); 
    void    set_coef(double a, double b, double c, double d);
    double  get_coef_a(void);
    double  get_coef_b(void);
    double  get_coef_c(void);
    double  get_coef_d(void);
    double  get_force();
    double convert(double mes);
    
};
#endif
