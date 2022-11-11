#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// gcc -W -Wall -o mySpitofy mySpitofy.c linkedList.c linkedListOfMusic.c
// ./mySpitofy > musiques
// diff musiques music.csv


Liste trouve_premier_min(Liste l){
    Liste minimum = l;
    Liste p = l;
    while(!estVide(p)){
        if( ((Music*)(p->val))->Year < ((Music*)(minimum->val))->Year ){
            minimum = p;
        }
        p = p->suiv;
    }
    return minimum;
}

Liste retire_premier_min(Liste l, int year){
	if(estVide(l)){return l;}
	if(((Music*)(l->val))->Year == year){
		l=(l->suiv);
	} else {
		(l->suiv) = retire_premier_min(l->suiv,year);
	}
	return l;
}

Liste trier_ordre_croissant(Liste l){
    Liste min,m;
    if(estVide(l)){
        return l;
    } else {
        min = trouve_premier_min(l);
        m = retire_premier_min(l,((Music*)(min->val))->Year);
        (min->suiv) = trier_ordre_croissant(m);
        return m;
    }
}



int main(void){
    Music musique[3000];                            //permet de ne pas creer de nouvelle musique a chaque tour de boucle
    Liste l;                                        //la liste des musiques
    FILE* f;                                        //le fichier
    char line[200];                                 //ligne en cours
    char* string;                                   //le composant de la musique en cours
    int i = 0;                                      //compteur de tour de boucle
    f=fopen("music.csv","r");

    printf("%s",fgets(line,200,f));                 //premiere ligne

    // for(int i = 0; i < 10;)
    while (fgets(line,200,f) != NULL) {
        string = strdup(line);
        musique[i].Name = strsep(&string,",");
        musique[i].Artist = strsep(&string,",");
        musique[i].Album = strsep(&string,",");
        musique[i].Genre = strsep(&string,",");
        musique[i].DiscNumber = atoi(strsep(&string,","));
        musique[i].TrackNumber = atoi( strsep(&string,",") );
        musique[i].Year = atoi( strsep(&string,",") );
        l = ajoutTete(&(musique[i]), l);
        i++;
    }
    fclose(f);

    afficheEnvers_r(l);

    // Liste l_triee = trier_ordre_croissant(l);
    // afficheListe_i(l_triee);
}