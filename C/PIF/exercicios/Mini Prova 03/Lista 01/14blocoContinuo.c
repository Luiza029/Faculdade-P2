#include <stdio.h>matriz
#include <stdlib.h>
#include <string.h>

int main() {
    int linha, coluna, *matriz, i, j, soma = 0;

    printf("Digite o tamanho de linha e da coluna: ");
    scanf("%d %d",&linha, &coluna);

    matriz = (int*) malloc((linha * coluna) * sizeof(int));

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            printf("Preencha o elemento [%d, %d]: ", i, j);
            scanf("%d", &matriz[i * coluna + j]);
        }
    }
    
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            soma += matriz[i * coluna + j];
        }
    }

    printf("Soma: %d", soma);

    free(matriz);
    return 0;
}