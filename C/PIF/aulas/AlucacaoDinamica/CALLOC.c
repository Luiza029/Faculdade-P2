#include <stdio.h>
#include <stdlib.h>

// Diferença de CALLOC para MALLOC: CALLOC possui dois parametros, o primeiro para a quantidade de elementos daquele tipo e o segundo é o tamanho daquele elemnto

int main() {
    char *x; 

    x = calloc(1, sizeof(char));

    if(x){
        printf("Memoria alocada com sucesso\n");
        printf("X = %c\n", *x);
        *x = 'A';
        printf("X = %c", *x);
    } else{
        printf("N foi possivel alocar a memoria\n");
    }

    return 0;
}