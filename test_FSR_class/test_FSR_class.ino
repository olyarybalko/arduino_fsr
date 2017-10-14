#include "FSR.h"
#include <Wire.h>

//Classe instance(la broche via laquelle on connecte la résistance vers CAN)
FSR sensor_hand(13);
FSR sensor_flor(12);
// le cas courant c'est l'utilisation des plusieurs capteurs

void setup()
{
Serial.begin(9600);

    sensor_hand.set_i2c_addr(4);
    sensor_flor.set_i2c_addr(4);
    
    /* appel des methodes specifiques */
    /* Le programmer l'utilisateur doit definir à l'avance */
    sensor_hand.set_coef_a(1.3);
    sensor_hand.set_coef_b(2.3);
    sensor_hand.set_coef_c(3.3);
    sensor_hand.set_coef_d(4.3);
    sensor_flor.set_coef_a(1.5);
    sensor_flor.set_coef_b(2.5);
    sensor_flor.set_coef_c(3.5);
    sensor_flor.set_coef_d(4.5);
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
  Serial.println(sensor_hand.get_force());
  Serial.println(sensor_flor.get_force());
  delay(1000);
}
