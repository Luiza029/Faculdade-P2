#include <stdio.h>

int maiorSeq(int n, int mat[][3]);

int main(){
    int n = 3, mat[3][3] = {{1,2,2},{1,2,7},{0,2,7}};
    
    int r = maiorSeq(n, mat);

    printf("%d", r);
    return 0;
}

int maiorSeq(int n, int mat[][3]){
    int i, j, maior = 0, cont = 0, indice = 0;

    for(j=0; j<n; j++){
        cont = 0;
        for(i=0; i<n-1; i++){
            if(mat[i][j] == mat[i+1][j]){
                cont++;
            }
        }
        if(cont > maior){
            maior = cont;
            indice = j;
        }
    }

    return indice;
}