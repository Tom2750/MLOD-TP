#include <stdint.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

enum Mois {jan = 1, fev, mars, avr, mai, juin, juil, aout, sept, oct, nov, dec};

struct Date {
    int jour;
    enum Mois mois;
    int annee;
};

void initialiseDate(struct Date *d){
    int j;
    enum Mois m;
    int a;
    printf("entrez le jour ");
    scanf("%d",&j);
    d->jour = j;
    printf("entrez le mois ");
    scanf("%d",&m);
    d->mois = m;
    printf("entrez l'année ");
    scanf("%d",&a);
    d->annee = a;
}

void afficheDate(struct Date *d){
    printf("%d",d->jour);printf(" ");
    printf("%d",d->mois);printf(" ");
    printf("%d",d->annee);printf(" ");
}

struct Date creerDateParCopie(){
    struct Date d;
    int j;
    enum Mois m;
    int a;
    printf("entrez le jour ");
    scanf("%d",&j);
    d.jour = j;
    printf("entrez le mois ");
    scanf("%d",&m);
    d.mois = m;
    printf("entrez l'année ");
    scanf("%d",&a);
    d.annee = a;
    return d;
}

int main(void){
    // struct Date d;
    // initialiseDate(&d);
    // afficheDate(&d);

    // struct Date e;
    // e = creerDateParCopie();
    // afficheDate(&e);

    struct Date *f;
    f = newDate();
    afficheDate(f);
    //...
    free(f);
    return 0;
}