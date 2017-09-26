#Introduction

Les résistances sensibles à la force (angl. FSR) sont des capteurs de forces à film polymères mince. Ce capteur est disponible dans le commerce et il est couramment utilisés dans une multitude d'applications de mesure biomécaniques ou dans la robotique interactive. Les raisons de cette utilisation étendue résident dans la polyvalence, le faible profil et le faible coût de ces capteurs.

Généralement, le capteur FSR est un dispositif analogique qui convertit la force d'une toucher dans une variation de la  résistance électrique. Ceci est associé aux difficultés de conversion de la résistance en force de contact en raison de sa dépendance non linéaire sur la force appliquée.

Pour une simple conversion force-tension, le dispositif FSR est lié à une résistance de mesure dans une configuration de diviseur de tension. La tension de sortie est décrite par l'équation:

\begin{equation}
V_{OUT} = \frac {(V^+)}{[1 + R_{FSR} / R]}
\end{equation}

ou $V^+$ - la tension d'entré ($5~V$), $R_{FSR}$ - la résistance du capteur, qui varie en fonction de la force appliquée, $R$ - résistance de mesure.

Pour chaque capteur, les équations d'étalonnage de la tension FSR à la charge appliquée  ont été déterminées en ajustant une équation logarithmique inverse comme recommandé [Interlink Electronics, 2015]:

F = a.e^{b.V} + c.e^{d.V}          


où $F$ représente la force prédite à partir de l'équation d'étalonnage, la tension mesurée V du FSR et $a$, $b$, $c$ et $d$ sont des constantes à résoudre pour chaque capteur et une combinaison de variables.

Pour trouver les constantes on a utilisé la fonction   f = fit(x,y,'exp2') dans Matlab.

Grace à l'approximation des tensions appliquées on a obtenu les courbes, qui sont illustrés aux Fig. \ref{fig_7}-\ref{fig_9}.

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

