#include <stdio.h>

int main() {
    int a = 123;
    int *pa;
    int **ppa;

    pa = &a;
    ppa = &pa;

    printf("a= %d\n", a);
    printf("*pa= %d\n", *pa);
    printf("*ppa= %d\n", **ppa);

    printf("\n");
    
    printf("\tMudanca do Conteudo: \n");

    *pa = 90;
    printf("a= %d\n", a);
    printf("*pa= %d\n", *pa);
    printf("*ppa= %d\n", **ppa);
    
    printf("\n");

    printf("\tMudanca de Endereco:\n");

    novoPonteiro(&pa); // a funcao muda o endereco apontado por PA
    printf("a= %d\n", a);
    printf("*pa= %d\n", *pa);
    printf("*ppa= %d\n", **ppa);

    return 0;
}

void novoPonteiro(int **pp){
    static int b = 4090;

    *pp = &b;
}