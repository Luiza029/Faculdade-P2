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
} Lista;

Lista *CriarLista(){ // vai criar um ponteiro lista que vai apontar para a struct Lista
    Lista *lista = malloc(sizeof(Lista)); // vai alocar 

    if(lista){
        lista -> cabeca = NULL;
        lista -> tam = 0;
    }

    return lista;
}

void inserirInicio(Lista *lista, int valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        
    }
}

int main() {
    
    return 0;
}