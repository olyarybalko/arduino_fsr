/*
  Actuator.h - Virtual class for any actuator integration.
  Created by Olga Melnyk, September 25, 2017.
  I use Arduino standard code indentation (Ctrl +T) and snake case for variables name.
*/
#ifndef ACTUATOR_H
#define ACTUATOR_H

class Actuator {
  public:
        //numero d'une broche vers laquelle un capteur sera connecte
        int _pin;
        //Constructor pametrisee
        Actuator(int pin): _pin(pin){}  
        //read function must be implemented this is called a pure virtual function
        virtual void short_pulse() = 0;
        virtual void long_pulse() = 0;
};
#endif
