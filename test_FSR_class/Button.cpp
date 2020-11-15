//include the class definition
#include "Button.h"

Button::Button (int pin): Sensor(pin) {}

bool Button ::is_pressed(void) //methode pour verifier est ce que la boutton est appuée
{
  if (digitalRead(_pin) == 0) return true;
  else return false;
}

bool Button :: is_avaible()   //initialiser la bouton attaché vers la broche numerique _pin correspond au dispositif présenté
{
   pinMode(_pin, INPUT_PULLUP);  // initialisation niveau bascule de la broche en tant que entrée
   _state = digitalRead(_pin);   // lecture de l'etat de la broche d'entrée numerique
   return 1;
}
