#pragma once

#include <stdbool.h>
#include "linkedList.h"

typedef struct{
	char* Name;
	char* Artist;
	char* Album;
	char* Genre;
	int DiscNumber;
	int TrackNumber;
	int Year;
} Music;

void afficheElement(Element e);

void detruireElement(Element e);

bool equalsElement(Element e1, Element e2);