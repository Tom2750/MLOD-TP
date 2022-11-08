
#include "linkedList.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void afficheElement(Element e){
    printf(e);
    printf("\n");
}

void detruireElement(Element e){}

bool equalsElement(Element e1, Element e2){
    return (strcmp(e1, e2) == 0);
}

int main(void){
    Liste l;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete("abc",l);
	l = ajoutTete("def",l);
	l = ajoutTete("ghi",l);

	afficheListe_i(l);

    ajoutFin_i("Phehe",l);
	afficheListe_i(l);

    printf("retirePremier_r(def)   : ");
	l = retirePremier_r("def",l);
	afficheListe_r(l);
}