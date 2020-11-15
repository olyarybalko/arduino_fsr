/*
  FSR.cpp - Library for communicate via TWI
  with slave uC with FSR sensors.
  Created by Olga Melnyk, September 25, 2017.
  Released into the public domain.
*/

#include "FSR.h"

//#define DEBUG 0

/*Ce constructeur est envoque automatiquement lors de la declaration d'une instance de la classe */
FSR::FSR (int pin, double a, double b, double c, double d): Sensor(pin)
{
  _a = a;
  _b = b;
  _c = c;
  _d = d;
}
/* Ce methode permet de lere la broche analogique vers laquelle le capteur est connecté 
Convertisseur analogique-numérique est a 10 bit, 2^10 = 1024*/
bool FSR::is_avaible() 
{
  // L' opérateur (ternaire) conditionnel renvoie vrai 
  // si FSR est connecte vers sa broche (les mesures autour de 0)
  // sinon renvoie faux (les mesures du bruit > 10)
  return analogRead(_pin) < 10 ? true : false;
  
}

/*
  Cette partie decrit des manipulateurs pour initialises les attributes, donc je créé,
  comme programmeur developpeur de la classe,
  une possibilite d'initialisation  des parametters.
  C'est exactement un programmeur utilisateur du classe connais
  le type de l'equipement et c'est a lui de definir via calibration des coefficients d'approximation
*/

/*   Mutateurs (setters) doivent etre implementés pous programmeur-utilisateur da la classe  */

void FSR::set_coef(double a, double b, double c, double d)
{
  _a = a;
  _b = b;
  _c = c;
  _d = d;
}

/*  Accesseurs (getters) doivent etre implementés pous programmeur-utilisateur da la classe  */

double FSR::get_coef_a(void)
{
  return _a;
}

double FSR::get_coef_b(void)
{
  return _b;
}

double FSR::get_coef_c(void)
{
  return _c;
}

double FSR::get_coef_d(void)
{
  return _d;
}

/* conversion du valeur brute en force */
double FSR::convert (double mesure)
{
  return  _a*exp(_b*mesure) + _c*exp(_d*mesure) ;
}

/* Lecture d'une valeur brute de capteur.*/
double FSR::get_force()
{
  double mesure;

  mesure = analogRead(_pin);

  return convert(mesure);
}


