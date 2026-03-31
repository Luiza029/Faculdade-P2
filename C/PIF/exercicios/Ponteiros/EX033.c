#include <stdio.h>

int main(){
    int var = 10;
    int *p = &var;

    *p = 100;

    printf("Valor de X: %d\n", var);
    printf("Endereco de X: %p\n", &var);

    printf("Valor apontado por p: %d\n", *p);
    printf("Endereco apontado por p :%p\n", p);
    printf("Endereco do ponteiro: %p\n", &p);

    return 0;
}