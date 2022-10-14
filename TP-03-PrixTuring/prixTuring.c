/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

typedef struct {
	int year;
	char *name;
	char *description;
} Winner;

void readWinner(Winner *w){
	w->year = scanLineAsInt();
	w->name = scanLine();
	w->description = scanLine();
}

Winner *readWinners(int nbGagnants){
	Winner *res = malloc(nbGagnants*sizeof(Winner));
	for(int i = 0; i < nbGagnants; i++){
		readWinner(&res[i]);
	}
	return res;
}

void printWinners(Winner* w, int nbGagnants){
	for(int i = 0; i < nbGagnants; i++){
		printf("%d",(w+i)->year);printf("\n");
		printf("%s",(w+i)->name);printf("\n");
		printf("%s",(w+i)->description);printf("\n");
	}
}

void sortTuringWinnersByYear(){
	
}

void infosAnnee(Winner* w, int nbGagnants, int annee){

	for(int i = 0; i < nbGagnants; i++){
		if((w+i)->year == annee){
			printf("L'annee %d, le(s) gagnant(s) ont été : %s\n",annee,(w+i)->name);
			printf("Nature des travaux : %s\n", (w+i)-> description);
		}
	}
}

int main(int argc, char *argv[]){

	int nbGagnants = scanLineAsInt();
	printf("%i\n",nbGagnants);

	Winner* w;
	w = readWinners(nbGagnants);

	// infosAnnee(w, nbGagnants, *argv[1]);
	infosAnnee(w, nbGagnants, 2011);

	for(int i = 0; i < nbGagnants; i++){
		free((w+i)->name);
		free((w+i)->description);
	}

	free(w);

	return EXIT_SUCCESS;
}


// int main(void) {
// 	int nbGagnants = scanLineAsInt();
// 	printf("%i\n",nbGagnants);
	
// 	Winner* w;
// 	w = readWinners(nbGagnants);

// 	printWinners(w,nbGagnants);

// 	for(int i = 0; i < nbGagnants; i++){
// 		free((w+i)->name);
// 		free((w+i)->description);
// 	}

// 	free(w);

// 	return EXIT_SUCCESS;
// }