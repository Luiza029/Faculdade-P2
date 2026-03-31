#include <stdio.h> 
int pares(int m[][3], int n){
    int i, j, cont = 0, qtd = 0;

    // como ele quer saber se as colunas sao pares, ent a coluna fica fixa e quem aumenta sao as linhas
    for(j=0; j<n; j++){
        cont = 0; // esqueci de reiniciar a variavel
        for(i=0; i<n; i++){
            if(m[i][j] % 2 == 0){
                cont++;
            }
        }
        if(cont == 3){
            qtd++;
        }
    }

    return qtd;
}

int main(){
    int mat[3][3] = {{2,2,4}, {6,4,2},{12,6,10}}, n = 3;

    printf("tiverem %d colunas inteiramente pares", pares(mat, n));
    return 0;
}