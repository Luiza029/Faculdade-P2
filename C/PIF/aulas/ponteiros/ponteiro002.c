#include <stdio.h>

int main(){
    int idade = 20;
    char sexo = 'f';
    float altura;
    double al;

    int *pi = &idade;
    char *ps = &sexo;
    float *paf = &altura;
    double *pad = &al;

    printf("Char: %d\n", sizeof sexo);
    printf("Int: %d\n", sizeof idade);
    printf("Float: %d\n", sizeof altura);
    printf("Double: %d\n", sizeof al);
   
    printf("\n");

    // O tamnho de um ponteiro depende do sistema, se o sistema for de 32bits, vai imprimir 4, se for de 64bits, imprimi 8
    printf("Char*: %d\n", sizeof ps);
    printf("Int*: %d\n", sizeof pi);
    printf("Float*: %d\n", sizeof paf);
    printf("Double*: %d\n", sizeof pad);

    return 0;
}