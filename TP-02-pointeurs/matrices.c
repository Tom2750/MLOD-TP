#include <stdint.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define ti 3
#define tk 2
#define tj 4

//matrice 1 de taille ti * tk
//matrice 2 de taille tk * tj
//donc matrice r de taille ti * tk

void matrix_mult(int64_t mR[ti][tj], int64_t m1[ti][tk], int64_t m2[tk][tj]){
    for(int i = 0; i < ti; i++){
        for(int j = 0; j < tj; j++){
            int s = 0;
            for(int k = 0; k < tk; k++){
                s += m1[i][k] * m2[k][j];
            }
            mR[i][j] = s;
        }
    }
}

void matrix_print(int64_t m[ti][tj]){
    for(int i = 0; i < ti; i++){
        for(int j = 0; j < tj; j++){
            printf("%" PRId64,m[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

int main(void){
    int64_t matrice1[ti][tk]={{1,2},{1,2},{1,2}};
    int64_t matrice2[tk][tj]={{6,7,8,9},{6,7,8,9}};
    int64_t matriceResultat[ti][tj];

    matrix_mult(matriceResultat,matrice1,matrice2);
    matrix_print(matriceResultat);

    return 0;
}