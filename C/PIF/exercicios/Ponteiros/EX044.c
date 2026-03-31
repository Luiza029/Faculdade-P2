#include <stdio.h>

int main(){
    int A = 20;
    int *p = &A;

    printf("Endereco: %p | Conteudo: %d\n", p, *p);

    *p = 12;
    printf("Endereco: %p | Conteudo: %d", p, *p);
    return 0;
}