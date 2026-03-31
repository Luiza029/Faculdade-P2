#include <stdio.h>

int PontodeSela(int n, int mat[][3]){
    int i, j, menor, coluna_menor = 0, MaiorDaColuna = 0, k = 0;

    for(i=0; i<n; i++){
        menor = mat[i][0];
        coluna_menor = 0;

        for(j=0; j<n; j++){
            if(mat[i][j] < menor){
                menor = mat[i][j];
                coluna_menor = i;
            }
        }

        MaiorDaColuna = 1;

        for(k=0; k<n; k++){
            if(mat[k][coluna_menor] > menor){
                MaiorDaColuna = 0; // sera falso
                break;
            }
        }

        if(MaiorDaColuna == 1){
            return menor;
        }
    }

    return -1;
}

int main(){
    int mat[3][3] = {{ 3, 8, 4 }, { 9, 7, 5 },{ 6, 2, 1 }}, n = 3;

    printf("%d", PontodeSela(n, mat));
    return 0;
}