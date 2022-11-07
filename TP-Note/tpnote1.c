#include <stdio.h>
#include <stdlib.h>

int main(void){
    int tab1[] = {1,2,4};
    int taille_tab1 = 3;
    int tab2[] = {10,3,8};
    int tab_final[7];                     //2eme fichier avec malloc

    int taille_final = repeat(tab1, taille_tab1, tab2, tab_final);

    for(int i = 0; i < taille_final ;i++){
        printf(" %d",tab_final[i]);
    }

    return 0;
}

int repeat(int tab1[], int taille_tab1, int tab2[], int tab_final[]){
    int taille_final = 0;                                    //taille du tableau final
    for(int i = 0; i<taille_tab1; i++){
        taille_final += tab1[i];
    }

    int indice_tab_final = 0;
    for(int i = 0; i<taille_tab1; i++){
        for(int j = 0; j<tab1[i]; j++){
            tab_final[indice_tab_final] = tab2[i];
            indice_tab_final += 1;
        }
    }

    return taille_final;
}