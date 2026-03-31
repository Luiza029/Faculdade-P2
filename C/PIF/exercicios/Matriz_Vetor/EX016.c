#include <stdio.h>

// Usar o void para printar matriz, ele vai pedir para retornar (indice por exemplo)

void preencher(int n, int matA[n][n], int matB[n][n], int matMult[n][n]);
void matriz(int n, int ma[][n], int mb[][n], int mmult[][n]);

int main(){
    int n = 3;
    int matA[n][n], matB[n][n], matMult[n][n];
    preencher(n, matA, matB, matMult);
    matriz(n, matA, matB, matMult);

    return 0;
}

void preencher(int n, int matA[n][n], int matB[n][n], int matMult[n][n]){
    int i, j;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("Preencher matriz A elemento[%d,%d]: ",i,j);
            scanf("%d", &matA[i][j]);
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("Preencher matriz B elemento[%d,%d]", i, j);
            scanf("%d", &matB[i][j]);
        }
    }
}

void matriz(int n, int ma[][n], int mb[][n], int mmult[][n]){
    int i, j, k;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            mmult[i][j] = 0;
            for(k=0; k<n; k++)
            mmult[i][j] += ma[i][k] * mb[k][j];
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", mmult[i][j]);
        }
        printf("\n");
    }
}