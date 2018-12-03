# Lem_in
Projet algorithmique utilisant la theorie des graphes.

input : une map que l'on transforme et stock sous forme de graph, cette map nous donne un nombre de fourmis,
plusieurs salles ( considere comme les sommets ), et des connections entre ces salles ( consideres comme les arretes ).
le graph est non pondere et non oriente.

consignes :
Une salle start et une salle end sont donnees, toutes les fourmis se trouvent dans la salle start au debut, le but est de
toutes les envoyees dans la salle end
il faut raisonner en tour par tour, à chaques tour il est possible de deplacer les fourmis de 1 sommet, cependant
il est impossible d'avoir deux fourmis dans le meme sommet durant un tour, ce qui revient a avoir un graph pondere
de 1 sur tous les sommet ( et non les arretes qui sont non ponderes ), ce qui complique beaucoup le probleme
car en fonction du nombre de fourmis la solutions ne sera pas la meme (gros nombres de fourmis = plus interessant 
de prendre deux longs chemins qu'un unique plus court, alors que si le nombre de fourmis est faible il est plus avantageux
de prendre un court chemin)

algorithmes utilises pour resoudre ce probleme :
BFS, pour trouver les plus courts chemins distinct, des qu'un chemins est trouve par le BFS, on bloque ce chemin, on 
reinitialise le graph et on relance un autre BFS sans rechercher dans les chemins trouve precedemment, ainsi on obtient
les plus courts distincts chemins.
ensuite on utilise un graph de residu ( principe des algorithmes de maximum flow ), pour trouver les flow bloquant,
ou plutot les arretes bloquantes, en partant du principe que chaques "arretes bloquantes" inverse fait apparaitre deux
chemins a la place d'un seul, le but est d'iterer sur toute les "arretes bloquantes" et de voir si il est plus rentable de
les inverser.


auto-critiques :
je pense arriver à un resultat assez correcte qui gere la plupart des cas basiques de shortcut, et qui reste raisonnable
en terme de temps d'execution.
cependant mon gros probleme est que l'iteration sur toutes les shortcut se fait de maniere aleatoire, lorsque je reverse
une shortcut ca impacte le reste de l'execution du programme et donc en fonction de l'ordre dans lequel les shortcut
seront regarde il est possible que je finisse avec une solution non optimal
