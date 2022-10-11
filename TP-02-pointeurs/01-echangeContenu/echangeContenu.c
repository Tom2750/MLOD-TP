#include "echangeContenu.h"
#include "stdio.h"
#include "stdlib.h"

void echangeContenu(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main(void){
    int a = 1;
    int b = 2;
    echangeContenu(&a,&b);
    printf("%d",a);
    return 0;
}