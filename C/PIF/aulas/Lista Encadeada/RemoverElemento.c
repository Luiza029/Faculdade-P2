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

No* remover(Lista *lista, int val){
    No *anterior, *remover = NULL;

    if(lista -> inicio){

        if(lista -> inicio -> valor == val){
            remover = lista -> inicio;
            lista -> inicio = remover -> proximo;
        }
        
        else{
            anterior = lista -> inicio;
            while(anterior -> proximo && anterior -> proximo -> valor != val)
            anterior = anterior -> proximo;
            if(anterior -> proximo){
                remover = anterior -> proximo;
                anterior -> proximo = remover -> proximo;
            }
        }
    }

    return remover;
}

int main() {
    
    return 0;
}