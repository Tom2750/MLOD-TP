#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>

void afficheElement(Element e){
	Music* m = (Music*)e;
	printf("%s",m->Name); printf(",");
	printf("%s",m->Artist); printf(",");
	printf("%s",m->Album); printf(",");
	printf("%s",m->Genre); printf(",");
	if(m->DiscNumber == 0){
		printf(",");
	} else{
		printf("%i",m->DiscNumber); printf(",");
	}

	if(m->TrackNumber == 0){
		printf(",");
	} else{
		printf("%i",m->TrackNumber); printf(",");
	}

	printf("%i",m->Year);
	printf("\n");
}

void detruireElement(Element e){bool a = e == 0;}

bool equalsElement(Element e1, Element e2){bool a = e1 == e2;
	return true;							// TODOOO
}