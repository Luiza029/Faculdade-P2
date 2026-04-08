#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int linha, i, j, **pascal;

    printf("Digite o tamanho da linha: ");
    scanf("%d", &linha);

    pascal = (int**) malloc(linha * sizeof(int*));

    for(i=0; i<linha; i++){
        pascal[i] = (int*) malloc((i+1) * sizeof(int));
    }


    for(i=0; i<linha; i++){
        for(j=0; j<i+1; j++){
            if(j == 0 || j == i){
                pascal[i][j] = 1;
            } else{
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
    }

    for(i=0; i<linha; i++){
        for(j=0; j<i+1; j++){
            printf("%d ", pascal[i][j]);
        }
        printf("\n");
    }
    return 0;
}