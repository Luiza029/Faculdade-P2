#include <stdio.h>

int main() {
    int x = 10;
    int *p;
    int **pp;

    p = &x;
    pp = &p;

    printf("\tX\n");
    printf("Valor de X: %d\n", x);
    printf("Endereco de X: %p\n", &x);

    printf("\n");

    printf("\tP\n");
    printf("Valor de P: %d\n", *p);
    printf("Endereco guardado em P: %p\n", p);
    printf("Endereco de P: %p\n", &p);

    printf("\n");
    
    printf("\tPP\n");
    printf("Valor de PP: %d\n", **pp);
    printf("Endereco guardado em PP: %p\n", pp);
    printf("Endereco de PP: %p\n", &pp);

    return 0;
}