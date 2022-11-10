#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
    Music musique[3000];
    Liste l;                                    //la liste des 3000 musiques
    FILE* f;                                    //le fichier
    char line[200];
    char* string;
    int i = 0;
    f=fopen("music.csv","r");

    printf("%s",fgets(line,200,f));



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