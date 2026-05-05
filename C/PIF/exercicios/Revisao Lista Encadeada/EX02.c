#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
} Node;

Node *CriarLista(int valor){
    Node *novo = malloc(sizeof(Node));

    novo->valor = valor;
    novo->proximo = NULL;

    return novo;
}

void add_inicio(Node **head, int valor){
    Node *novo = CriarLista(valor);
    novo->proximo = *head;
    *head = novo;
}

void imprimir(Node **head){
    Node *aux = *head;
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux -> proximo;
    }
}

int main() {
    Node *head = NULL;

    add_inicio(&head, 10);
    add_inicio(&head, 20);
    add_inicio(&head, 30);

    imprimir(&head);

    return 0;
}