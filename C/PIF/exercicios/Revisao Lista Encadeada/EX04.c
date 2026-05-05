#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node* proximo;
} Node;

Node *criarLista(int valor){
    Node *novo = malloc(sizeof(Node));
    novo ->valor = valor;
    novo ->proximo = NULL;

    return novo;
}

void add(Node **head, int valor){
    Node *novo = criarLista(valor);
    novo ->proximo = *head;
    *head = novo;
    
    
}

int contar(Node **head){
    Node *aux = *head;
    int cont = 0;

    while(aux != NULL){
        cont++;
        aux = aux -> proximo;
    }

    return cont;
}

void Imprimir(Node **head){
    Node *aux = *head;

    while(aux != NULL){
        printf("%d ", aux -> valor);
        aux = aux -> proximo;
    }
}

int main() {
    Node *head = NULL;

    add(&head, 10);
    add(&head, 20);
    add(&head, 30);

    Imprimir(&head);
    int r = contar(&head);
    printf("\nQtd:%d", r);

    return 0;
}