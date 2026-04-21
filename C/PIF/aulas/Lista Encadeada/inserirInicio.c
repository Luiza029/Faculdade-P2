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

void inserirInicio(Lista *lista, int valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo -> valor = valor; // vai receber o novo valor
        novo -> proximo = lista -> inicio; // O novo nó aponta para o antigo primeiro nó, que pode ser null se a lista estiver vazia
        lista -> inicio = novo; // agr o começo da nova lista é esse novo nó
    } else{
        printf("Erro ao alocar memoria");
    }
}

int main() {
    
    return 0;
}