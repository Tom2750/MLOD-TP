#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CHUNK_SIZE_MAX 5

struct cellule_s {
	struct cellule_s* next;
    int chunkSize;
	char chunk[];
};

typedef struct cellule_s Cellule;

typedef Cellule* String;

// créé un string d'un seul élément contenant le char c
String creerString(char c){
    String s = malloc(sizeof(Cellule));
    (s->chunk)[0] = c;
    s->chunkSize = 1;
    return s;
}

// créé un String avec la chaine de caractere s
String string_new(char* chaine){
    String s, cellule_actuelle;
    //initialisation
    s = cellule_actuelle;
    int i = 0;
    char char_actuel = chaine[i];

    while(!((int)char_actuel == (int)"!")){
        if(i%5 == 0){                                   //on a fini avec la celulle actuelle et on passe à la suivante
            (cellule_actuelle->next) = creerString(char_actuel);
            cellule_actuelle = cellule_actuelle->next;
        } else {                                        // on remplit la cellule actuelle
            (cellule_actuelle->chunkSize) += 1;
            (cellule_actuelle->chunk)[i%5] = char_actuel;
        }
        i += 1;
        char_actuel = chaine[i];
    }
    return s;
}

//retourne vrai si la liste est vide et faux sinon
bool estVide(String s){
    return s == NULL;
}
//il manque la fonction afficher chaine, donc on l'implémente
void afficherString_r(String s){
    if(!(estVide(s))){
        for(int i = 0; i < s->chunkSize; i++){
            printf("%s",(s->chunk)[i]);
        }
        afficherString_r(s->next);
    }
}

int main(void){

    String s = string_new("Hello !");
    // afficherString_r(s);
    return 0;
}