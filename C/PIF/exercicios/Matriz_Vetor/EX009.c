#include <stdio.h>
#include <stdlib.h>

int Diferenca(int n, int m[][3], int gab[]){
    int i, j, diferanca = 0, menor = 0, vet[3], indiceMenor = 0;

    for(i=0; i<n; i++){
        diferanca = 0;
        for(j=0; j<n; j++){
            diferanca += abs(m[i][j] - gab[j]);
        }
        vet[i] = diferanca;
    }

    menor = vet[0];
    for(i=0; i<n; i++){
        if(vet[i] < menor){
            menor = vet[i];
            indiceMenor = i;
        }
    }

    return indiceMenor;
}

int main(){
    int mat[3][3] = {{1,6,9}, {6,2,1},{10,12,3}}, vet[3] = {10,10,10}, n = 3;
    
    printf("%d", Diferenca(n, mat, vet));
    return 0;
}