#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
    Music musique[3000];                            //permet de ne pas creer de nouvelle musique a chaque tour de boucle
    Liste l;                                        //la liste des musiques
    FILE* f;                                        //le fichier
    char line[200];                                 //ligne en cours
    char* string;                                   //le compoasant de la musique en cours
    int i = 0;                                      //compteur de tour de boucle
    f=fopen("music.csv","r");

    printf("%s",fgets(line,200,f));                 //premiere ligne

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

    afficheEnvers_r(l);

    fclose(f);
}

void trieDecroissant(Liste l){
    Liste minimum = l;                  //pointe sur la liste commencant par le minimum
    Liste p = l;                        //pointe sur la cellule en cours
    while(!estVide(p)){
        if( ((Music*)(p->val))->Year < ((Music*)(minimum->val))->Year ){
            minimum = p;
        }
        p = p->suiv;
    }
}