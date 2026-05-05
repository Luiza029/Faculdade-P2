#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
}Node;

Node *criarLista(int valor){
    Node *novo = malloc(sizeof(Node));
    novo ->valor = valor;
    novo ->proximo = NULL;

    return novo;
}

void addFim(Node **head, int valor){
    Node *novo = criarLista(valor);

    if(*head == NULL){
        *head = novo;

    } else{
        Node *aux = *head;

        while(aux -> proximo != NULL){
            aux = aux ->proximo;
        }

        aux ->proximo = novo;
    }
}

void imprimir(Node **head){
    if(*head){
        Node *aux = *head;

        while(aux != NULL){
            printf("%d ", aux ->valor);
            aux = aux -> proximo;
        }
    }
}

int main() {
    Node *head = NULL;

    addFim(&head, 10);
    addFim(&head, 20);
    addFim(&head, 30);

    imprimir(&head);
    return 0;
}