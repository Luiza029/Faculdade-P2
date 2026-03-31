#include <stdio.h>
#include <stdlib.h>

// A funcao free vai liberar aquela regiao de memoria

int main() {
    int *x;

    x = malloc(sizeof(int));

    if(x){
        *x = 50;
        printf("%d\n", *x);
        free(x);
        printf("%d", *x);

    } else{
        printf("Erro ao alocar memoria!\n");
    }
    
    return 0;
}