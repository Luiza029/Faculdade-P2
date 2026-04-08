#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int linha, coluna, **matriz, i, j;

    printf("Digite o tamanho de linhas e colunas: ");
    scanf("%d %d", &linha, &coluna);

    matriz = (int**) malloc(linha * sizeof(int*));

    for(i=0; i<linha; i++){
        matriz[i] = (int*) malloc(coluna * sizeof(int));
    }

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            printf("Preencha o valor do elemento[%d, %d]: ", i, j);
            scanf("%d", &matriz[i][j]);
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