#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int valor;
    struct No *proximo;
} No;

typedef struct Lista{
    int *inicio;
    int tam;
} Lista;

No *pesquisar(No *inicio, int val){ // val = valor que quer procurar
    while(inicio && inicio -> valor != val) // apenas inicio (verifica se inicio nao é null)
        inicio = inicio -> proximo;

    return inicio;
}

int main() {
    
    return 0;
}