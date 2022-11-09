#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>

void afficheElement(Element e){
	Music* m = (Music*)e;
	printf("%s",m->Name); printf(" ");
	printf("%s",m->Album); printf(" ");
	printf("%s",m->Artist); printf(" ");
	printf("%s",m->Genre); printf(" ");
	printf("%i",m->DiscNumber); printf(" ");
	printf("%i",m->TrackNumber); printf(" ");
	printf("%i",m->Year); printf(" ");
	printf("\n");
}

void detruireElement(Element e){}

bool equalsElement(Element e1, Element e2){
	return true;
}