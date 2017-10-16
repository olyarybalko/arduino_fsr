#Introduction

Les résistances sensibles à la force (angl. FSR) sont des capteurs de forces à film polymères mince. Ce capteur est disponible dans le commerce et il est couramment utilisés dans une multitude d'applications de mesure biomécaniques ou dans la robotique interactive. Les raisons de cette utilisation étendue résident dans la polyvalence, le faible profil et le faible coût de ces capteurs.

Généralement, le capteur FSR est un dispositif analogique qui convertit la force d'une toucher dans une variation de la  résistance électrique. Ceci est associé aux difficultés de conversion de la résistance en force de contact en raison de sa dépendance non linéaire sur la force appliquée.

Pour une simple conversion force-tension, le dispositif FSR est lié à une résistance de mesure dans une configuration de diviseur de tension. Pour chaque capteur, les équations d'étalonnage de la tension FSR à la charge appliquée  ont été déterminées en ajustant une équation logarithmique inverse comme recommandé [Interlink Electronics, 2015]:

F = a.e^{b.V} + c.e^{d.V}          


où $F$ représente la force prédite à partir de l'équation d'étalonnage, la tension mesurée V du FSR et $a$, $b$, $c$ et $d$ sont des constantes à résoudre pour chaque capteur et une combinaison de variables.

Pour trouver les constantes on a utilisé la fonction   f = fit(x,y,'exp2') dans Matlab.


Pour commencer le projet je crée la classe FSR :

class FSR
{

};

il est preferable d'attribuer le nom parlant pour votre class, dans ce cas c'est un abbreviation "force sensetive resistor" = FSR 

Bien sur class contiendra de méthodes et d'attributs.

de variables, ici appelées attributs (on parle aussi de variables membres) ;
de fonctions, ici appelées méthodes (on parle aussi de fonctions membres). :


Cette étape demande de réflexion et de comprehension du mecanisme de communication entre dispositifs physiques pour lesquel le classe sera developpé.
Avant le codage est essentielle quand on fait de la POO.
Les méthodes, elles, sont grosso modo les actions que le personnage peut effectuer ou qu'on peut lui faire faire.

Les méthodes

Les méthodes manipulent les attributs. Certains methodes lisent les atributes et modifient

Voici quelques actions réalisables avec notre FSR :

recevoirDegats: le personnage prend un certain nombre de dégâts et donc perd de la vie.
attaquer: le personnage attaque un autre personnage avec son arme. Il inflige autant de dégâts que son arme le lui permet (c'est-à-diredegatsArme).
boirePotionDeVie: le personnage boit une potion de vie et regagne un certain nombre de points de vie.
changerArme: le personnage récupère une nouvelle arme plus puissante. On change le nom de l'arme et les dégâts qui vont avec.
estVivant: renvoietruesi le personnage est toujours vivant (il possède plus que 0 point de vie), sinon renvoiefalse.
C'est un bon début, je trouve.

On va rajouter cela dans la classe avant les attributs (en POO, on préfère présenter les méthodes avant les attributs, bien que cela ne soit pas obligatoire) :
 

Les attributs

C'est ce qui va caractériser votre classe, ici le personnage. Ce sont des variables, elles peuvent donc évoluer au fil du temps. Mais qu'est-ce qui caractérise un personnage de jeu de rôle ? Allons, un petit effort.

Par exemple, tout personnage a un niveau de vie. Hop, cela fait un premier attribut : vie ! On dira que ce sera unintet qu'il sera compris entre 0 et 100 (0 = mort, 100 = toute la vie).
Dans un jeu de rôle, il y a le niveau de magie, aussi appelé mana. Là encore, on va dire que c'est unintcompris entre 0 et 100. Si le personnage a 0 de mana, il ne peut plus lancer de sort magique et doit attendre que son mana se recharge tout seul au fil du temps (ou boire une potion de mana !).
On pourrait rajouter aussi le nom de l'arme que porte le joueur : nomArme. On va utiliser pour cela unstring.
Enfin, il me semble indispensable d'ajouter un attribut degatsArme, unintqui indiquerait cette fois le degré de dégâts que porte notre arme à chaque coup.
On peut donc déjà commencer à compléter la classe avec ces premiers attributs :





******* Start init *****

1.30

2.30

3.30

4.30

********* Second **************

1.50

2.50

3.50

4.50


******* End init ******

100.04

124.73

100.04

124.73

100.04

124.73

100.04

124.73

