#include "linkedListOfMusic.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
    Element musique;
    musique.Name = "gege";
    musique.Artist = "ag";
    musique.Album = "azefazef";
    musique.Genre = "aert";
    musique.DiscNumber = 2;
    musique.TrackNumber = 3;
    musique.Year = 3;
    afficheElement(musique);

    FILE* f;
    f=fopen("music.csv","r");
}