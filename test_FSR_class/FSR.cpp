/*
  FSR.cpp - Library for communicate via TWI 
  with slave uC with FSR sensors.
  Created by Olga Melnyk, September 25, 2017.
  Released into the public domain.
*/

#include "Arduino.h"

#include "FSR.h"

/*Ce constructeur est envoque automatiquement lors de la declaration d'une instance de la classe */

FSR::FSR(int address)
{
  // TODO check if the address is correct
  
  Wire.begin();        // join i2c bus (address optional for master)
  _a = 0.0;
  _b = 0.0;
  _c = 0.0;
  _d = 0.0;
  _address = address;
  _pin = 0;
}


void
FSR::set_i2c_pin(int pin)

{ 
  //TO DO check if the pin is correct
    _pin = pin;
    
  Wire.beginTransmission(_address); // transmit to device #_address
  Wire.write(_pin);              // sends one byte
  Wire.endTransmission();    // stop transmitting
    
}
/*
Cette partie decrit des manipulateurs pour initialises les attributes, donc je créé,
comme programmeur developpeur de la classe, 
une possibilite d'initialisation  des parametters.
C'est exactement un programmeur utilisateur du classe connais
le type de l'equipement et c'est a lui de definir via calibration des coefficients d'approximation
*/

void
FSR::set_coef_a(double value)

{ 
    _a = value;
}

void
FSR::set_coef_b(double value)

{ 
    _b = value;
}

void
FSR::set_coef_c(double value)

{ 
    _c = value;
}

void 
FSR::set_coef_d(double value)

{ 
    _d = value;
}

/* getters */

double
FSR::get_coef_a(void)

{ 
    return _a;
}

double
FSR::get_coef_b(void)

{ 
    return _b;
}

double
FSR::get_coef_c(void)

{ 
    return _c;
}

double
FSR::get_coef_d(void)

{ 
    return _d;
}

double
FSR::get_force()

{
  int nb = 8,i, receivedValue;
  double force;
  Serial.print ("get_force ");
  
  Serial.print (_address); 
  Serial.print (" ");
  Serial.print (_pin); 
  Serial.print (" ");
  Serial.print (this->_a); 
  Serial.print (" ");
  
  if (_address == -1)
  {
    Serial.println("ERROR, Address does not well defined");
    return -1.1;
  }
  
  Wire.requestFrom(_address, 16);    // request 16 bytes from slave device #_address
  i = 0;
  while(Wire.available())
  {    // slave may send less than requested
    receivedValue  = Wire.read() << 8;
    receivedValue |= Wire.read();
    
    Serial.print (receivedValue); 
    Serial.print (" ");
    
    if(i==_pin) 
    {
      force =  receivedValue;
    }
    i++;
  } 
  return force;
}


