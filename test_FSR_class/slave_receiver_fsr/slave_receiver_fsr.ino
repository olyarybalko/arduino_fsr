// Wire Slave Sender
// by Olga Melnyk<http://www.>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 08 Octobre 2017

// This example code is in the public domain.


#include <Wire.h>

void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  }

void loop()
{
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{

  while (1 < Wire.available()) // loop through all but the last
  {
    int result = -1;
    int x = Wire.read(); // receive byte as a character
    if (x>0 && x<6)
    result = 1;//analogRead(x);
    else result = -1;
    Wire.write(result);
   } 
}
