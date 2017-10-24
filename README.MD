# Introduction

Les résistances sensibles à la force (angl. FSR) sont des capteurs de forces à film polymères mince. Ce capteur est disponible dans le commerce et il est couramment utilisés dans une multitude d'applications de mesure biomécaniques ou dans la robotique interactive. Les raisons de cette utilisation étendue résident dans la polyvalence, le faible profil et le faible coût de ces capteurs.

Généralement, le capteur FSR est un dispositif analogique qui convertit la force d'une toucher dans une variation de la résistance électrique. Ceci est associé aux difficultés de conversion de la résistance en force de contact en raison de sa dépendance non linéaire sur la force appliquée.

Pour une simple conversion force-tension, le dispositif FSR est lié à une résistance de mesure dans une configuration de diviseur de tension. Pour chaque capteur, les équations d'étalonnage de la tension FSR à la charge appliquée ont été déterminées en ajustant une équation logarithmique inverse comme recommandé [Interlink Electronics, 2015]:

F (V) = a.e^{b.V} + c.e^{d.V}          


où F représente la force prédite à partir de l'équation d'étalonnage, la tension mesurée V du FSR et a, b, c et d sont des constantes à résoudre pour chaque capteur et une combinaison de variables.

Pour trouver les constantes on a utilisé la fonction   f = fit(x,y,'exp2') dans Matlab.


une schéma du mise en place des microcontrôleurs est présente

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

Il est préférable d'attribuer le nom parlant pour votre class, dans ce cas c'est un abréviation "force sensitive résistor" = FSR

Bien sûr class contiendra de méthodes et d'attributs.

De variables, ici appelées attributs (on parle aussi de variables membres) ; de fonctions, ici appelées méthodes (on parle aussi de fonctions membres).

Cette étape demande de réflexion et de compréhension du mécanisme de communication entre dispositifs physiques pour lesquels le classe sera développé. Avant le codage est essentielle quand on fait de la POO. Les méthodes, elles, sont grosso modo les actions que le personnage peut effectuer ou qu'on peut lui faire faire.


# Constructeur

Constructeur est amélioré dans cette version. Désormais il est indispensable de fournir (1) l'adresse du microcontrôleur esclave, (2) la broche via laquelle la résistance est connectée vers le CAN du microcontrôleur esclave et (3) des coefficients d'approximation. Si l'approximation est envisagée via une expovente, il suffit de ne pas fournir les deux derniers coefficients.

FSR::FSR(int address, int pin,  double a, double b, double c = 0.0, double d = 0.0)
{
  // TODO check if the address is correct

  Wire.begin();        // join i2c bus (address optional for master)
  _a = a;
  _b = b;
  _c = c;
  _d = d;
  _address = address;
  _pin = pin;//_

}


# Méthodes

Les méthodes manipulent les attributs. Certains méthodes lisent les attributs et modifient

Voici quelques actions réalisables avec notre FSR :
---
set_i2c_addr(int): attribuer une adress physique  pour le uC esclave.

set_coef_a(double) et set_coef_b(double) sont accesseurs (setters) pour affecter vers valeurs numérique aux coefficients de premier membre de l'approximation a.e^{b.V}.

set_coef_c(double) et set_coef_d(double) idem pour deuxième membre de l'équation c.e^{d.V}

get_coef_a(void), get_coef_b(void), get_coef_c(void) et get_coef_d(void): sert à accéder vers la valeur d'un des coefficients pour l'affichage ou des calculs intermédiaires.

double  get_force(): le méthode principale, qui demande à microcontrôleur esclave des données et les réceptionne via I2C.

---
On va rajouter cela dans la classe avant les attributs (en POO, on préfère présenter les méthodes avant les attributs, bien que cela ne soit pas obligatoire) :

# Attributs

C'est ce qui va caractériser la classe conçue. Ce sont des variables, elles peuvent donc évoluer au fil du temps a cause de changement de la température du milieu ambiant.
