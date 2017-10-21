/*
MEGA 2560
*/
#include "FSR.h"
#include <Wire.h>

//Classe instance(l'adresse du uC escalave )
FSR sensor_hand(4);
FSR sensor_flor(4);
// le cas courant c'est l'utilisation des plusieurs capteurs

void setup()
{
Serial.begin(9600);

//(la broche via laquelle  la résistance est  connectee vers CAN)
    sensor_hand.set_i2c_pin(3);
    sensor_flor.set_i2c_pin(4);
    
    /* appel des methodes specifiques */
    /* Le programmer l'utilisateur doit definir à l'avance */
    /* dans le README.MD il y a des explications de la provenance des coefficients*/
    sensor_hand.set_coef_a(9.046536);
    sensor_hand.set_coef_b(1.105736);
    sensor_hand.set_coef_c(-9.402752);
    sensor_hand.set_coef_d(-2.026341);
    sensor_flor.set_coef_a(7.653104);
    sensor_flor.set_coef_b(1.098430);
    sensor_flor.set_coef_c(-8.284287);
    sensor_flor.set_coef_d(-2.919219);
    Serial.println("******* Start init *****");
    Serial.println(sensor_hand.get_coef_a());
    Serial.println(sensor_hand.get_coef_b());
    Serial.println(sensor_hand.get_coef_c());
    Serial.println(sensor_hand.get_coef_d());
    Serial.println("***********************");
    Serial.println(sensor_flor.get_coef_a());
    Serial.println(sensor_flor.get_coef_b());
    Serial.println(sensor_flor.get_coef_c());
    Serial.println(sensor_flor.get_coef_d());
    Serial.println("******* End init ******");
}

void loop()
{
  Serial.print(" ");
  
  Serial.print(sensor_hand.get_force());
  
  Serial.print(" ");
   
  Serial.println(sensor_flor.get_force());
  
  delay(1000);
}
