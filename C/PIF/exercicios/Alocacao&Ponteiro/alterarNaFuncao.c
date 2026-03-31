#include <stdio.h>

int main() {
    int a = 50;
    int *p;
    int **pp;

    p = &a;
    pp = &p;
    
    printf("Valor de A: %d\n", a);
    printf("Valor de P: %d\n", *p);
    printf("Valor de PP: %d\n", **pp);

    alterar(&p);

    printf("Variaveis Alteradas\n");
    printf("Valor de A: %d\n", a);
    printf("Valor de P: %d\n", *p);
    printf("Valor de PP: %d\n", **pp);

    return 0;
}

void alterar(int **pp){
    static int b = 1000;

    *pp = &b; 
}