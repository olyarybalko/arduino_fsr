/*
  slave_receiver.ino
  Created by Olga Melnyk, September 25, 2017.
  I use Arduino standard code indentation (Ctrl +T) and snake case for variables name.
*/
#include"Button.h"          //classe développée pour boutons poussoires (derivée classe abstraite Sensor)
#include "Tactile.h"        //classe développée pour moteur à vibration (derivée classe abstraite Actuator)
#include <TM1637Display.h>  //classe thierse pour afficheur LED à 7-segments.
#include"FSR.h"             //classe développé pour resistances sensibles aux pression (derivée classe abstraite Sensor)
#include"Error.h"           //classe développé pour afficher l'error sur afficheur LED à 7-segments 

#define CLK 10  // definition des broches pour afficheur LED à 7-segments.       
#define DIO 11  // correspond au dispositif présenté

/* Variables avec la visibilite globale*/

Button button(6);  //declaration d'une instance (un objet button) de la classe développée Button
Tactile tactile(5);  //declaration d'une instance (un objet tactile) de la classe développée Tactile
TM1637Display display(CLK, DIO);  //declaration et initialisation d'une instance (un objet display) de la classe thierse TM1637Display
FSR fsr(0, 2.986e-17, 0.06384,  0.009505,  0.009133);  //declaration et initialisation d'une instance (un objet display) de la classe développée Fsr
FSR fsr1(7, 2.986e-17, 0.06384,  0.009505,  0.009133);
FSR fsr2(6, 2.986e-17, 0.06384,  0.009505,  0.009133);

int flag = 0;  //variable pour manipuler l'execution du programme;

void setup() { // cette fonction s'execute une fois durant le demarage (imposé par la convention Arduino)
  Serial.begin(9600);           // etre pret pour la communication via port serie
  display.setBrightness(0x0f);  // definir la Luminosité  de l'afficheur LED

  if (!button.is_avaible())
    display.setSegments(SEG_ERR_BUTTON);

  if (!fsr.is_avaible())
    display.setSegments(SEG_ERR_FSR);

  if (!fsr1.is_avaible())
    display.setSegments(SEG_ERR_FSR1);

  if (!fsr2.is_avaible())
    display.setSegments(SEG_ERR_FSR2);
}

void loop() {    // cette fonction s'execute infiniment apres l'execution obligatoire de setup (c'est imposé par la convention Arduino)
  delay(500);

  display.setSegments(SEG_DONE);  //message sur LED

  if (button.is_pressed())
    flag = !flag;  // verification d'etat de la bouton

  while (flag)  // mesure et affichage jusqu'à l'appui de nouveau sur la bouton
  {
    delay (500);

    int val = (int)  fsr.get_force(); //mesure de la force appliquée
    int val1 = (int)  fsr1.get_force();
    int val2 = (int)  fsr2.get_force();
    int total = val + val1 + val2;

    if (total < 9999)
      display.showNumberDec(total); //affichage de la valeur mesurée
    else
      display.setSegments(SEG_ERR_MAX);  //message Erreur LED

    if (total > 1000)
      tactile.short_pulse(); // motif tactile envoyé si valeur depasse un seuil

    if (button.is_pressed())
      flag = !flag; //si bouton est appuyé de nouveau on change le drapeau
  }
}
