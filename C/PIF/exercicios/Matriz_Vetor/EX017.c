#include <stdio.h>

int soma(int n, int mat[][n]);

int main(){
    int n = 3, mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    int r = soma(n, mat);
    printf("%d", r);
    return 0;
}

int soma(int n, int mat[][n]){
    int i, j, soma = 0;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(j > i){
                soma += mat[i][j]; 
            }
        }
    }

    return soma;
}