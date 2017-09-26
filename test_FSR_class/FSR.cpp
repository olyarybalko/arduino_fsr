/*
  FSR.cpp - Library for communicate via TWI 
  with slave uC with FSR sensors.
  Created by Olga Melnyk, September 25, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include <Wire.h>
#include "FSR.h"


FSR::FSR(int pin)
{
  Wire.begin();        // join i2c bus (address optional for master)
  _a = 0.0;
  _b = 0.0;
  _c = 0.0;
  _d = 0.0;
  _address = -1;
  _pin = pin;
}


void FSR::set_i2c_addr(int address)
{ 
  //TO DO check if the adress is correct
    _address = address;
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
  if (_address == -1){
    Serial.println("ERROR, Address does not well defined");
    return -1.1;}

    char c [10];
    int  i = 0;
    Wire.requestFrom(_address, 10);    // request 10 bytes from slave device #8

  while (Wire.available() || i <= 10) { // slave may send less than requested
     c[i] = Wire.read(); // receive a byte as character
     i++;
    //Serial.print(c);         // print the character
  }


   return _a*pow(2.17,_b) + _c*pow(2.17,_d);
}