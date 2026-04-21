#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int valor;
    struct No *proximo;
} No;

typedef struct Lista{
    No *inicio;
    int tam;
} Lista;


void inserirOrdenado(Lista *lista, int valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo -> valor = valor;
        if(lista -> inicio == NULL || lista -> inicio -> valor > novo -> valor){
            novo -> proximo = lista -> inicio;
            lista -> inicio = novo;

        }else{
            No *aux = lista -> inicio;
            while(aux -> proximo && aux -> proximo -> valor < novo -> valor)
                aux = aux -> proximo;
            novo -> proximo = aux -> proximo;
            aux -> proximo = novo;
        } 

    } 
    else{
        printf("Erro ao alocar memoria");
    }
}


int main() {
    
    return 0;
}