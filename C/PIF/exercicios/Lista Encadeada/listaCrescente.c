#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
}Node;

Node *criarLista(int valor){
    Node *novo = malloc(sizeof(Node));
    novo -> valor = valor;
    novo -> proximo = NULL;

    return novo;
}

void addOrdenada(Node **head, int valor){
    Node *novo = criarLista(valor);

    if(*head == NULL || valor < (*head) ->valor){
        novo ->proximo = *head;
        *head = novo;
    } else{
        Node *aux = *head;
        Node *anterior =*head;
        while(aux != NULL && aux->valor < valor){
            anterior = aux;
            aux = aux->proximo;
        }
        anterior ->proximo = novo;
        novo->proximo = aux;
    }
}

Node *misturar(Node *l1, Node *l2){
    Node *head = NULL;
    head = criarLista(l1->valor);
    Node *aux = head;

    while(l1 != NULL || l2 != NULL){
        if(l2 != NULL){
            aux = aux ->proximo;
            l2 = l2 ->proximo;
        }
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

    addOrdenada(&head, 10);
    addOrdenada(&head, 50);
    addOrdenada(&head, 90);
    addOrdenada(&head, 20);

    printf("Lista: ");
    imprimir(&head);
    return 0;
}