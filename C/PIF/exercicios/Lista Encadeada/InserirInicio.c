#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int valor;
    struct No *proximo;
} No;

typedef struct Lista{
    No *cabeca;
    int tam;
}Lista;

void inserirInicio(Lista *lista, int valor){
    No *novo = malloc(sizeof(novo));

    if(novo){
        novo -> valor = valor;
        novo -> proximo = lista -> cabeca;
        lista -> cabeca = novo;
    
    } else{
        printf("Erro ao alocar memoria\n");
    }
}


int main() {
    
    return 0;
}