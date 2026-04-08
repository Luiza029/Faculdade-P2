#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int linha, coluna, **matriz, i, j, chave;

    printf("Digite o tamanho de linhas e colunas: ");
    scanf("%d %d", &linha, &coluna);

    matriz = (int**) malloc(linha * sizeof(int*));

    for(i=0; i<linha; i++){
        matriz[i] = (int*) malloc(coluna * sizeof(int));
    }

    printf("Digite um numero: ");
    scanf("%d", &chave);
    srand(chave);

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            matriz[i][j] = rand() % 100;
        }
    }

    printf("matriz normal: \n");
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Matriz Transposta: \n");
    for(i=0; i<coluna; i++){
        for(j=0; j<linha; j++){
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }

    for(i=0; i<linha; i++){
        free(matriz[i]);
    }

    free(matriz);
    return 0;
}