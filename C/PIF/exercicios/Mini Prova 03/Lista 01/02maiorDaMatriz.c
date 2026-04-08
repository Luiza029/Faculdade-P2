#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int **matriz, linha, coluna, i, j, maior ;

    printf("Digite o tamanho das linhas e das colunas: ");
    scanf("%d %d",&linha, &coluna);

    matriz = (int**) malloc(linha * sizeof(int*));

    for(i=0; i<linha; i++){
        matriz[i] = (int*) malloc(coluna * sizeof(int));
    }

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            printf("Digite o elemento [%d,%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    maior = matriz[0][0];

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            }
        }
    }

    printf("Maior = %d", maior);

    for(i=0; i<linha; i++){
        free(matriz[i]);
    }

    free(matriz);
    matriz = NULL;

    return 0;
}