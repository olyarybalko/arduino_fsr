#include "FSR.h"

FSR sensor_hand(13);
FSR sensor_flor(12);

void setup()
{
Serial.begin(9600);
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
