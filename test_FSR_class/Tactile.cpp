//include the class definition
#include "Tactile.h"

Tactile::Tactile (int pin): Actuator(pin) {}

void Tactile::short_pulse()  // Méthode pour générer une motif tactile vibratoire durant 100 ms
{
  long ti = millis();     // recuperer le temps courant en milliseconds
  while (millis() - ti < 100) // executer durant 100 milliseconds le cœur de la boucle
    analogWrite(_pin, 1023);   // activer le moteur à vibration (dispositif recoit l'alimentation 3.3 V)
  analogWrite(_pin, 0);    // desactiver le moteur à vibration (dispositif ne recoit pas d'alimentation)
}

void Tactile::long_pulse()      // Méthode pour générer une motif tactile vibratoire durant 500 ms
{
  long ti = millis();
  while (millis() - ti < 500)    // executer durant 500 milliseconds le cœur de la boucle
    analogWrite(_pin, 1023);
  analogWrite(_pin, 0);
}
