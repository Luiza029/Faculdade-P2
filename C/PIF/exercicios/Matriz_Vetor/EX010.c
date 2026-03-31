#include <stdio.h>

int Soma(int n, int mat[][n], int vet[]){
    int i, j, soma = 0, maior = 0, indiceMaior = 0;

    for(i=0; i<n; i++){
        soma = 0;
        for(j=0; j<n; j++){
            if(mat[i][j] > vet[j]){
                soma += (mat[i][j] - vet[j]);
            }
        }

        if(soma > maior){
            maior = soma;
            indiceMaior = i;
        }
    }

    return indiceMaior;
}

int main(){
    int mat[3][3] = {{4,1,2}, {5,6,2},{8,4,1}}, n = 3, vet[3] = {6,2,3};

    printf("%d", Soma(n, mat, vet));
    return 0;
}