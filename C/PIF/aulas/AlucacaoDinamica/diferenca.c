#include <stdio.h>
#include <stdlib.h>

// A diferenca entre as duas é que malloc coloca um lixo de memoria e calloc nao coloca lixo de memoria (caso n tenha declarado valores para a variavel)

int main() {
    int *x, *y;

    x = malloc(2 * sizeof(int));
    y = calloc(2, sizeof(int));

    if(x && y){ // so entra se as duas tiverem mamorias alocadas
        printf("Memorias alocadas com sucessos!\n");
        printf("\tMALLOC: %d %d\n", *x, *(x+1));
        printf("\tCALLOC: %d %d\n", *y, *(y+1));
    } else{
        printf("Erro ao alocar memoria!\n");
    }
    return 0;
}