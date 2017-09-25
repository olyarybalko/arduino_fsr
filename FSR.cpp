/*
  FSR.cpp - Library for communicate via TWI 
  with slave uC with FSR sensors.
  Created by Olga Melnyk, September 25, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "FSR.h"

FSR::FSR(int pin)
{
  pinMode(pin, OUTPUT);
  _a = 0.0;
  _b = 0.0;
  _c = 0.0;
  _d = 0.0;
  _pin = pin;
}


void FSR::set_coef_a(double value)
{ 
    _a = value;
}

void FSR::set_coef_b(double value)
{ 
    _b = value;
}

void FSR::set_coef_c(double value)
{ 
    _c = value;
}

void FSR::set_coef_d(double value)
{ 
    _d = value;
}

double FSR::get_coef_a(void)
{ 
    return _a;
}

double FSR::get_coef_b(void)
{ 
    return _b;
}

double FSR::get_coef_c(void)
{ 
    return _c;
}

double FSR::get_coef_d(void)
{ 
    return _d;
}

double FSR::get_force()
{ 
  
    return _a*pow(2.17,_b) + _c*pow(2.17,_d);
}
