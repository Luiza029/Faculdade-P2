#include <stdio.h>

int soma(int n, int mat[][3], int vetSoma[]);

int main(){
    int n = 3, mat[3][3] = {{1,2,3},{0,1,3},{5,10,5}}, vetSoma[3] = {6,2,20};

    int r = soma(n, mat, vetSoma);
    printf("%d", r);
    return 0;
}

int soma(int n, int mat[][3], int vetSoma[]){
    int i, j, soma = 0, ehIgual = 1;

    for(i=0; i<n; i++){
        soma = 0;
        for(j=0; j<n; j++){
            soma += mat[i][j];
        }

        if(soma != vetSoma[i]){
            ehIgual = 0;
        }
    }

    if(ehIgual == 1){
        return 1;
    } else{
        return 0;
    }
}