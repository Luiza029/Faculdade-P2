#include <stdio.h>

int main(){
    int i, j, tam;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tam);

    int matrizA[tam][tam], matrizB[tam][tam], matrizSoma[tam][tam];

    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            printf("Digite os elemento da matriz A [%d,%d]: ", i,j);
            scanf("%d", &matrizA[i][j]); // esqueci de colocar as posicoes do I e do J
        }
    }

    printf("\n");

    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            printf("Digite os elementos da matriz B [%d, %d]: ", i, j);
            scanf("%d", &matrizB[i][j]);
        }
    }

    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            matrizSoma[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    for(i=0; i<tam; i++){
        for(j=0; j<tam; j++){
            printf("%d ", matrizSoma[i][j]);
        }
        printf("\n");
    }

    return 0;
}