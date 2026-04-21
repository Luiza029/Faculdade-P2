#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// lista encadedada é mais flexivel que pilha e fila. Posso colocar itens em qualquer lugar (inicio, meio e fim)

typedef struct{
    int valor;
    struct No *proximo;
} No;

typedef struct{
    No *inicio;
    int tam;
} Lista;

Lista *criarLista(){
    Lista *lista = malloc(sizeof(Lista));

    if(lista){
        lista -> inicio = NULL;
        lista -> tam = 0;
    }

    return lista;
}

void inserirFim(Lista *lista, int valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo -> valor = valor;
        novo -> proximo = NULL; // define como o ultimo

        if(lista -> inicio == NULL){ // se a lista estiver vazia, o novo nó vira o primeiro (e o ultimo tbm)
            lista -> inicio = novo;
        } else{
            No *aux = lista -> inicio; // se nao estiver vazia, cria uma aux que aponta para o primeiro nó 
            while(aux -> proximo){ // anda até o ultimo 
                aux = aux -> proximo; // aux esta no ultimo
            }
            aux -> proximo = novo; // ultimo recebe o novo 
        }
    } else{
        printf("Erro ao alocar memoria");
    }
}

int main() {
    
    return 0;
}