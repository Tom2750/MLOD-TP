#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool estUnDiviseur(int i, int n){
    if(n%i == 0){
        return true;
    } else {return false;}
}

int sommeDiviseurs(int n){
    int s = 0;
    for(int i = 1; i < n; i++){
        if(estUnDiviseur(i,n)){
            s += i;
        }
    }
    return s;
}

int nombreParfait(int n){
    int sd = sommeDiviseurs(n);
    if(sd == n){
        return n;
    } else {return -1;}
}

int main(void){
    int n = 30;
    for(int i = 0; i <= n; i++){
        int a = nombreParfait(i);
        if(a != -1){
            printf("%d",nombreParfait(i));
            printf("\n");
        }

    }
}