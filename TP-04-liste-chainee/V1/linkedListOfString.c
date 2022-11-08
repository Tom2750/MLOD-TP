
#include "linkedList.c"
#include <stdlib.h>
#include <stdio.h>

void afficheElement(Element e){printf("%c",e);}

void detruireElement(Element e){}

bool equalsElement(Element e1, Element e2){
    return (int)e1 == (int)e2;
}

int main(void){
    Liste l;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete('a',l);
	l = ajoutTete('b',l);
	l = ajoutTete('c',l);
	l = ajoutTete('d',l);
	l = ajoutTete('e',l);
	l = ajoutTete('f',l);
	l = ajoutTete('g',l);
	l = ajoutTete('h',l);
	l = ajoutTete('i',l);

	afficheListe_i(l);

    ajoutFin_i('P',l);
	afficheListe_i(l);

    printf("retirePremier_r(e)   : ");
	l = retirePremier_r('e',l);
	afficheListe_r(l);
}