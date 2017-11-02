
# Avant propos

In the master branch I puting v.0.1 product which can be downloaded by final users.
https://stackoverflow.com/questions/20755434/what-is-the-master-branch-and-release-branch-for

I have the devel branch to test features.

To build the OOP I had inspired from
https://www.arduino.cc/en/Hacking/LibraryTutorial

# Introduction

Les résistances sensibles à la force (angl. FSR) sont des capteurs de forces à film polymères mince. Ce capteur est disponible dans le commerce et il est couramment utilisés dans une multitude d'applications de mesure biomécaniques ou dans la robotique interactive. Les raisons de cette utilisation étendue résident dans la polyvalence, le faible profil et le faible coût de ces capteurs.

Généralement, le capteur FSR est un dispositif analogique qui convertit la force d'une toucher dans une variation de la  résistance électrique. Ceci est associé aux difficultés de conversion de la résistance en force de contact en raison de sa dépendance non linéaire sur la force appliquée.

Pour une simple conversion force-tension, le dispositif FSR est lié à une résistance de mesure dans une configuration de diviseur de tension. Pour chaque capteur, les équations d'étalonnage de la tension FSR à la charge appliquée  ont été déterminées en ajustant une équation logarithmique inverse comme recommandé [Interlink Electronics, 2015]:

F (V) = a.e^{b.V} + c.e^{d.V}          


où F représente la force prédite à partir de l'équation d'étalonnage, la tension mesurée V du FSR et a, b, c et d sont des constantes à résoudre pour chaque capteur et une combinaison de variables.

Pour trouver les constantes on a utilisé la fonction   f = fit(x,y,'exp2') dans Matlab.


une schema du mise en place des microcontroleurs est presente
https://www.tinkercad.com/things/7MTtN5MlWVk-fabulous-borwo-hango/editel?sharecode=0hwKuulfnewsQBzYmb8pIYtYYfpcV2A0WH9uxV-qnfk=

data is loaded from file Calibration_1_123D.txt, data contains 25 rows and 2 columns

-3219.096241

2.190379

3231.599754

2.189066

data is loaded from file Calibration_2_126AF.txt, data contains 25 rows and 2 columns

7.653104

1.098430

-8.284287

-2.919219

data is loaded from file Calibration_3_123D.txt, data contains 25 rows and 2 columns

68.332017

0.623610

0.000000

0.623610

data is loaded from file Calibration_4_123BC.txt, data contains 25 rows and 2 columns

9.046536

1.105736

-9.402752

-2.026341

# Création de la classe FSR

Pour commencer le projet je crée la classe FSR :

class FSR {

};

il est préférable d'attribuer le nom parlant pour votre class, dans ce cas c'est un abréviation "force sensitive résistor" = FSR

Bien sur class contiendra de méthodes et d'attributs.

de variables, ici appelées attributs (on parle aussi de variables membres) ; de fonctions, ici appelées méthodes (on parle aussi de fonctions membres).

Cette étape demande de réflexion et de compréhension du mécanisme de communication entre dispositifs physiques pour lesquels le classe sera développé. Avant le codage est essentielle quand on fait de la POO. Les méthodes, elles, sont grosso modo les actions que le personnage peut effectuer ou qu'on peut lui faire faire.

Les méthodes

Les méthodes manipulent les attributs. Certains méthodes lisent les attributs et modifient

Voici quelques actions réalisables avec notre FSR :
---
set_i2c_addr(int): attribuer une adresse physique  pour le uC esclave.

set_coef_a(double) et set_coef_b(double) sont accesseurs (setters) pour affecter  des valeurs numérique aux coefficients de premier membre de l'approximation a.e^{b.V}.

set_coef_c(double) et set_coef_d(double) idem pour deuxième membre de l'équation c.e^{d.V}

get_coef_a(void), get_coef_b(void), get_coef_c(void) et get_coef_d(void):serent a acceder vers la valeur d'un des coefficients pour l'affichage ou des calculs intermediares.

double  get_force(): le méthode principale, qui demande à microcontrôleur esclave des données et les réceptionne via I2C.

---
On va rajouter cela dans la classe avant les attributs (en POO, on préfère présenter les méthodes avant les attributs, bien que cela ne soit pas obligatoire) :

Les attributs

C'est ce qui va caractériser la classe conçue. Ce sont des variables, elles peuvent donc évoluer au fil du temps a cause de changement de la température du milieu ambiant.

// TODO
Réfléchir à propos de constat comme prédicat.



Résultat de l'exécution du code .ino



F1 (V1) = 9.046536*e^(1.105736*V1) - 9.402752*e^{-2.026341*V1}

F2 (V2) = 7.653104*e^(1.098430*V2) - 8.284287*e^{-2.919219*V2}

Pour cette parametres

sensor_hand.set_i2c_pin(3);

sensor_flor.set_i2c_pin(4);

sensor_hand.set_coef_a(9.046536);

sensor_hand.set_coef_b(1.105736);

sensor_hand.set_coef_c(-9.402752);

sensor_hand.set_coef_d(-2.026341);

sensor_flor.set_coef_a(7.653104);

sensor_flor.set_coef_b(1.098430);

sensor_flor.set_coef_c(-8.284287);

sensor_flor.set_coef_d(-2.919219);

# Debug

******* Start init *****

9.05

1.11

-9.40

-2.03

***********************

7.65

1.10

-8.28

-2.92

******* End init ******

 get_force 4 3 9.05 0 1 2 3 4 5 6 7 3.00 get_force 4 4 7.65 0 1 2 3 4 5 6 7 4.00

 get_force 4 3 9.05 0 1 2 3 4 5 6 7 3.00 get_force 4 4 7.65 0 1 2 3 4 5 6 7 4.00

 get_force 4 3 9.05 0 1 2 3 4 5 6 7 3.00 get_force 4 4 7.65 0 1 2 3 4 5 6 7 4.00

 get_force 4 3 9.05 0 1 2 3 4 5 6 7 3.00 get_force 4 4 7.65 0 1 2 3 4 5 6 7 4.00

 get_force 4 3 9.05 0 1 2 3 4 5 6 7 3.00 get_force 4 4 7.65 0 1 2 3 4 5 6 7 4.00

 get_force 4 3 9.05 0 1 2 3 4 5 6 7 3.00 get_force 4 4 7.65 0 1 2 3 4 5 6 7 4.00

 get_force 4 3 9.05 0 1 2 3 4 5 6 7 3.00 get_force 4 4 7.65 0 1 2 3 4 5 6 7 4.00
 
 ![primer](https://www.dropbox.com/s/ggn4gkqm79kxwtz/proposed.png)
