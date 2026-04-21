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

int main() {
    
    return 0;
}