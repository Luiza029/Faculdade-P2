#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int linha, coluna, **matriz, i, j, soma = 0;

    printf("Digite a quantidade de linha e coluna: ");
    scanf("%d %d", &linha, &coluna);

    matriz = (int**) malloc(linha * sizeof(int*));

    for(i=0; i<linha; i++){
        matriz[i] = (int*) malloc(coluna *sizeof(int));
    }

    printf("Preencha a matriz:\n");
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            printf("Elemento[%d,%d]", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i=0; i<linha; i++){
        soma = 0;
        for(j=0; j<coluna; j++){
            soma += matriz[i][j];
        }
        printf("Soma da linha %d: %d\n", i, soma);
    }

    for(i=0; i<linha; i++){
        free(matriz[i]);
    }

    free(matriz);
    return 0;
}
