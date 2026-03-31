#include <stdio.h>

int main(){
    char frase[100];
    char *p;

    // Quando for fazer leitura de texto, n precisa do & no scanf
    scanf("%100[^\n]", frase);
    printf("Frase Digitada: %s\n", frase);

    printf("Frase:\t\t%p\n", frase);
    printf("&Frase:\t\t%p\n", &frase);
    printf("&Frase[0]:\t%p\n", &frase[0]);

    p = frase;
    printf("Valor de P:\t%p \tValor apontado: %c\n", p, *p);
    return 0;
}