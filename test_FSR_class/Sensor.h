/*
  Sensor.h - Virtual class for any sensor integration.
  Created by Olga Melnyk, September 25, 2017.
  I use Arduino standard code indentation (Ctrl +T) and snake case for variables name.
*/

#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
  public:
    //numero d'une broche vers laquelle un capteur sera connecte
    int _pin;
    //Constructor pametrisee
    Sensor(int pin): _pin(pin) {}
    // fonction virtuelle prete reutilisation
    virtual bool is_avaible() = 0;
};
#endif
