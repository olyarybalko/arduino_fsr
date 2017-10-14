/*
  FSR.cpp - Library for communicate via TWI 
  with slave uC with FSR sensors.
  Created by Olga Melnyk, September 25, 2017.
  Released into the public domain.
*/

#include "Arduino.h"

#include "FSR.h"

/*Ce constructeur est envoque automatiquement lors de la declaration d'une instance de la classe */

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
/*
Cette partie decrit des manipulateurs pour initialises les attributes, donc je créé,
comme programmeur developpeur de la classe, 
une possibilite d'initialisation  des parametters.
C'est exactement un programmeur utilisateur du classe connais
le type de l'equipement et c'est a lui de definir via calibration des coefficients d'approximation
*/

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

/* getters */

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
  Serial.print ("get_force ");
  Serial.println (_address);
//  
//  union asdf
//  {
//  char asd[2];
//  int dsa;
//  } fdsa;
//     int  i = 0;
//  
//  if (_address == -1){
//    Serial.println("ERROR, Address does not well defined");
//    return -1.1;}


 
    
//  Wire.beginTransmission(_address); // transmit to device #4
//  Wire.write( _pin);              // sends one byte
//  Wire.endTransmission();    // stop transmitting
//  
//  Serial.println("end transmission");
   
  Wire.requestFrom(_address, 2);    // request 10 bytes from slave device #8


 
//  while (Wire.available() && i <= 2) { // slave may send less than requested
//      Serial.print(i); Serial.print(" ");
//      fdsa.asd[i] = Wire.read(); // receive a byte as character
//      i++;
//    //Serial.print(c);         // print the character
//  }
//
//
//   //return _a*pow(2.17,_b) + _c*pow(2.17,_d);
//   return fdsa.dsa;
int receivedValue;
     Wire.requestFrom(4, 12);    // request 6 bytes from slave device #2
  while(Wire.available()){    // slave may send less than requested
    receivedValue  = Wire.read() << 8;
    receivedValue |= Wire.read();
    Serial.print(receivedValue);
Serial.print(" ");  }
Serial.println();

   return receivedValue;
}
