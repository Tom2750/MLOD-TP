# MiniProjet

Description du Projet
_______________________________________________________________________________________________
Le jeu "gorilas" a été modifié. Ce jeu se joue à deux joueurs. Tour à tour ces joueurs se tirent une balle dessus et le but est de détruire le joueur adverse.
Ce jeu se joue entièrement avec la souris. La touche "p" permet de mettre le jeu en Pause et la touche "Entrée" permet de relancer la partie une fois celle-ci finie. 

Une nouvelle fonctionnalité a été implémentée: la présence d'un bouclier bleu autour de chaque joueur les protégeants.
De plus, une IA a été créée afin de pouvoir jouer en solo contre l'ordinateur.
Le fichier "duel_d_IA.c" permet d'assister à un duel d'IA.




Comment compiler et exécuter
_______________________________________________________________________________________________
Il faut avoir au préalable installer Raylib sur sa machine.
se rendre dans le répertoire du projet : "cd MLOD-TP/MiniProjet"

jouer contre l'IA : "cc jouer_contre_IA.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11"
		    "./a.out"

duel d'IA : "cc duel_d_IA.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11"
	    "./a.out"




Détail du code
_______________________________________________________________________________________________

Partie IA :
Dans le moteur du jeu, on fait appel à la fonction UpdatePlayer si le joueur est réel et UpdateIA sinon.
Comportement de l'IA : elle tire un premier shoot, puis ajuste son shoot suivant en fonction du précédent :
		       si elle n'a pas tiré assez fort, elle tire un peu plus fort de manière aléatoire
		       et un peu moins fort sinon.

Partie boucliers :
Les boucliers se comportent comme des batiments. Il faut cependant faire attention de ne pas tirer dans le bouclier du joueur actuel.
Les dessins sont gérés dans la fonction "DrawGame" et les collisions avec les balles dans "UpdateBall".

