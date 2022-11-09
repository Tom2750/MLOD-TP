#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
    Music musique;

    musique.Name = "gege";
    musique.Artist = "ag";
    musique.Album = "azefazef";
    musique.Genre = "aert";
    musique.DiscNumber = 2;
    musique.TrackNumber = 3;
    musique.Year = 3;

    Liste l = creer(&musique);

    //lecture du fichier
    FILE* f;
    f=fopen("music.csv","r");

    char buffer[100];

    // found = strsep(&string," ")) != NULL
    while(fgets(buffer,100,f) != NULL ) {
        printf(" %s",buffer);
    // char* found;

    // for(int i = 0; i < 5; i++){
    //     found = strsep(&string,", ") != NULL
    // printf("%s",found);
    }
    fclose(f);
}