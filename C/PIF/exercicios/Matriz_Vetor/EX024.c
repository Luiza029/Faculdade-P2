#include <stdio.h>

int qtd_coluna(int n, int mat[][3]);

int main(){
    int mat[3][3] = {{0,0,0},{4,8,9},{0,7,0}}, n = 3;

    int r = qtd_coluna(n, mat);
    printf("%d", r);
    return 0;
}

int qtd_coluna(int n, int mat[][3]){
    int i, j, qtd = 0, maior = 0, indice = 0;

    for(j=0; j<n; j++){
        qtd = 0;
        for(i=0; i<n; i++){
            if(mat[j][i] == 0){
                qtd++;
            }
        }

        if(qtd > maior){
            maior = qtd;
            indice = j;
        }
    }

    return indice;
}