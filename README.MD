# Introduction

Les résistances sensibles à la force (angl. FSR) sont des capteurs de forces à film polymères mince. Ce capteur est disponible dans le commerce et il est couramment utilisés dans une multitude d'applications de mesure biomécaniques ou dans la robotique interactive. Les raisons de cette utilisation étendue résident dans la polyvalence, le faible profil et le faible coût de ces capteurs.

Généralement, le capteur FSR est un dispositif analogique qui convertit la force d'une toucher dans une variation de la  résistance électrique. Ceci est associé aux difficultés de conversion de la résistance en force de contact en raison de sa dépendance non linéaire sur la force appliquée.

Pour une simple conversion force-tension, le dispositif FSR est lié à une résistance de mesure dans une configuration de diviseur de tension. Pour chaque capteur, les équations d'étalonnage de la tension FSR à la charge appliquée  ont été déterminées en ajustant une équation logarithmique inverse comme recommandé [Interlink Electronics, 2015]:

F (V) = a.e^{b.V} + c.e^{d.V}          


où $F$ représente la force prédite à partir de l'équation d'étalonnage, la tension mesurée V du FSR et $a$, $b$, $c$ et $d$ sont des constantes à résoudre pour chaque capteur et une combinaison de variables.

Pour trouver les constantes on a utilisé la fonction   f = fit(x,y,'exp2') dans Matlab.


Pour commencer le projet je crée la classe FSR :

class FSR {

};

il est preferable d'attribuer le nom parlant pour votre class, dans ce cas c'est un abbreviation "force sensetive resistor" = FSR

Bien sur class contiendra de méthodes et d'attributs.

de variables, ici appelées attributs (on parle aussi de variables membres) ; de fonctions, ici appelées méthodes (on parle aussi de fonctions membres). :

Cette étape demande de réflexion et de comprehension du mecanisme de communication entre dispositifs physiques pour lesquel le classe sera developpé. Avant le codage est essentielle quand on fait de la POO. Les méthodes, elles, sont grosso modo les actions que le personnage peut effectuer ou qu'on peut lui faire faire.

Les méthodes

Les méthodes manipulent les attributs. Certains methodes lisent les atributes et modifient

Voici quelques actions réalisables avec notre FSR :
---
set_i2c_addr(int): attribuer une adress physique  pour le uC esclave.

set_coef_a(double) et set_coef_b(double) sont acsesseurs (setters) pour affecter vel valeurs numerique aux coefficients de premire membre de l'approximation a.e^{b.V}.

set_coef_c(double) et set_coef_d(double) idem pour deuxieme membre de l'equation c.e^{d.V}

get_coef_a(void), get_coef_b(void), get_coef_c(void) et get_coef_d(void):serent a acceder vers la valeur d'un des coefficients pour l'affichage ou des calculs intermediares.

double  get_force(): le methode principale, qui demande à microcontroleur esclave des données et les receptionne via I2C.

---
On va rajouter cela dans la classe avant les attributs (en POO, on préfère présenter les méthodes avant les attributs, bien que cela ne soit pas obligatoire) :

Les attributs

C'est ce qui va caractériser la classe conçue. Ce sont des variables, elles peuvent donc évoluer au fil du temps a cause de changement de la temperature du milieux embiant.

// TODO
Reflechir a propos de const comme predicat.



Resultat de l'execution du code .ino
Cela n'a pas du sence l'initialisation au piff

F1 (V) = 1.3*e^(2.3*V1) + 3.33*e^{4.3*V1}
F2 (V) = 1.5*e^(2.5*V1) + 3.5*e^{4.5*V1}


******* Start init *****
1.30
2.30
3.30
4.30
***********************
1.50
2.50
3.50
4.50
******* End init ******
get_force 4
11111 222 333 444 555 666
666.00
get_force 4
11111 222 333 444 555 666
666.00
get_force 4
11111 222 333 444 555 666
666.00
get_force 4
11111 222 333 444 555 666
666.00
get_force 4
11111 222 333 444 555 666
666.00
get_force 4
11111 222 333 444 555 666
666.00
