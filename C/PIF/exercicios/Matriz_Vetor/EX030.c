#include <stdio.h>

int Limite(int n, int mat[][3], int vetLim[]);

int main(){
    int n = 3, mat[3][3] = {{5,1,10},{11,2,8},{7,3,4}}, vetLim[3] = {4,9,8};

    int r = Limite(n, mat, vetLim);
    printf("%d", r);
    return 0;
}

int Limite(int n, int mat[][3], int vetLim[]){
    int i, j, cont = 0, maior = 0, indice;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(mat[i][j] > vetLim[i]){
                cont++;
            }
        }

        if(cont > maior){
            maior = cont;
            indice = i;
        }
    }

    return indice;
}