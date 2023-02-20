# Projet_S9 : L'étude de la fluorescence de nouvelles molécules pour la théranostique 

Réunion 27/10/2022 :
  - présentation du projet par le référent 


Réunion 5/11/2022 :
  - Répartition des tâches entre les membres du groupe 
  - rédaction du rapport n°1 
  - Début du Gantt 

Réunion 17/11/2022 : 

  - première organisation du code 
  - Début du diagramme UML
  
A faire pour la prochaine séance 25/11/2022 : 

- recherches bibliographiques sur programmation + scanner+ fonctionnalisation
- avancement du code 

Réunion 29/11/2022 :

- reunion avec notre tuteur 
- explication des différents fichiers à notre disposition



Explication CODE : 

Partie 2 : Informations liées aux spectres de fluorescence 

Préliminaires : 
- récupérer les vecteurs longueur d'onde et acquisitions
- dans le vecteur acquisitions, il y differents fichiers d'acquisition numérotée. Chaque fichier d'acquistion contient 10 répétitions. Chaque répétition contient 10 lignes soit 10 spectres + une ligne qui est le fond lumineux.

Etape 1 : Définir une plage de longueur d'onde sur laquelle nous allons calculer l'intégrale en faisant la somme des différentes intensités de l'indice de départ à l'indice d'arrivée. 

Etape 2 : Création de la fonction intégrale qui calcule l'intégrale en faisant la somme. Cette fonction prend en argument chaque ligne d'un fichier acquisition (par exemple acq01). Elle prend également en argument l'indice de départ et d'arrivée, c'est-à-dire la plage sur laquelle va etre calculé l'intégrale. La fonction calcule alors la somme des différentes valeurs de la ligne. 

Etape 3 : Stocker les différentes sommes obtenues dans un vecteur.

Etape 4 : Création d'une fonction moyenne qui va calculer la moyenne du vecteur contenant les integrales. Cette fonction prend en argument le vecteur ainsi que la taille du vecteur. 
