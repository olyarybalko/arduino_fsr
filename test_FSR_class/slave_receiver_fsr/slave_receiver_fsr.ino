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
  //Wire.onReceive(receiveEvent); // register event
   Wire.onRequest(requestEvent); // register event
  }

void loop()
{
delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
//void receiveEvent(int howMany)
//{
//
//  while (1 < Wire.available()) // loop through all but the last
//  {
//    int result = 256;
//   // int x = Wire.read(); // receive byte as a character
//   // if (x>0 && x<6)
//   // result = 1;//analogRead(x);
//  //  else result = -1;
//    Wire.write(result);
//   } 
//}

void requestEvent()
{
  //a range of -32,768 to 32,767
  int input = 11111;//analogRead(0);
  uint8_t buffer[12];
  buffer[0] = input >> 8;
  buffer[1] = input & 0xff;
  
     input = 222;//analogRead(1);
  
  buffer[2] = input >> 8;
  buffer[3] = input & 0xff;
 
    input = 333;//analogRead(2);

  buffer[4] = input >> 8;
  buffer[5] = input & 0xff;

    input = 444;//analogRead(3);
  
  buffer[6] = input >> 8;
  buffer[7] = input & 0xff;

    input = 555;//analogRead(6);
  
  buffer[8] = input >> 8;
  buffer[9] = input & 0xff;
  
    input = 666;//analogRead(7);
  
  buffer[10] = input >> 8;
  buffer[11] = input & 0xff;
  Wire.write(buffer, 12);
  
}
