/*
MEGA 2560
*/
#include "FSR.h"
#include <Wire.h>

/* Classe instance(l'adresse du uC escalave )
Le programmer l'utilisateur doit definir à l'avance (1) l'adresse du microcontroleur esclave, (2) la broche via laquelle la résistance est connectee vers le CAN du microcontroleur esclave et (3) des coefficients d'approximation.
dans le README.MD il y a des explications de la provenance des coefficients 
*/

FSR sensor_hand(4, 1, 9.046536, 1.105736, -9.402752, -2.026341);
FSR sensor_flor(4, 2, 7.653104, 1.098430, -8.284287, -2.919219);
// le cas courant c'est l'utilisation des plusieurs capteurs

void setup()
{
Serial.begin(9600);


    
    /* appel des methodes specifiques */

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
