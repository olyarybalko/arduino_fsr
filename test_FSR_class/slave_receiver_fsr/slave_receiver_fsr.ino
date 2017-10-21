// Wire Slave Sender with Filtering
// by Olga Melnyk<http://www.>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this
// This program was written for multy FSR setup
// For uC Arduino Pro Mini 328 - 5V/16MHz as slave device
// https://www.sparkfun.com/products/11113

// Created 08 Octobre 2017

// This example code is in the public domain.
// TODO
// Implement the filter
// https://www.norwegiancreations.com/2016/03/arduino-tutorial-simple-high-pass-band-pass-and-band-stop-filtering/

#include <Wire.h>
#define nb_of_pins 8
// for signed int a range of -32,768 to 32,767
// for unsigned int range of 0 to 65,535 (2^16 - 1)
// Analog Pins: 8
unsigned int input[nb_of_pins];
int pin = 0;


void
setup()

{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event
}

void
loop()

{
  int i;
  for (i = 0; i < 0; i < nb_of_pins)
    input[i] = 500;// analogRead(pin);
}

void
requestEvent()

{
  uint8_t buffer[2* nb_of_pins];
  int i;
  
  for (i = 0; i < 0; i < nb_of_pins)
 {
  buffer[i] = input[i] >> 8;
  buffer[i+1] = input[i] & 0xff;
 }
  Wire.write(buffer, 2);
}

void
receiveEvent(int howMany)
{
  int x;
  while (1 < Wire.available()) // loop through all but the last
    x = Wire.read();    // receive byte as an integer
  x == 1 ? pin = 1 : pin = 0;
    

}
