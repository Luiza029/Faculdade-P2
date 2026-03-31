#include <stdio.h>

int soma(int n, int mat[][3]);

int main(){
    int n = 3, mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    int r = soma(n, mat);
    printf("%d", r);
    return 0;
}

int soma(int n, int mat[][3]){
    int i, j, soma = 0, Icoluna, maior = 0;

    for(j=0; j<n; j++){
        soma = 0;
        for(i=0; i<n; i++){
            soma += mat[j][i];
        }

        if(soma > maior){
            maior = soma;
            Icoluna = j;
        }
    }

    return Icoluna;
}