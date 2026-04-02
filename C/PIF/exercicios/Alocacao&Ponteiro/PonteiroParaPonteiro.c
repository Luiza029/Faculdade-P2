#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int l, c, i, j;

    int **matriz;

    printf("Digite o numero de linha e de coluna de uma matriz: ");
    scanf("%d %d", &l, &c);

    // construir a matriz
    matriz = (int**) malloc(l * sizeof(int*)); // cria os enderecos das linhas

    for(i=0; i<l; i++){
        matriz[i] = (int*) malloc(c * sizeof(int)); // cria os vetores secundarios para as colunas
    }

    // preencher
    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            matriz[i][j] = i + j;
        }
    }

    // Printar
    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // esvaziar
    for(i=0; i<l; i++){
        free(matriz[i]);
    }

    free(matriz);
    matriz = NULL;


    return 0;
}