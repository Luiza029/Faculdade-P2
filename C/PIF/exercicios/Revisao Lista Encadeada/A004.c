#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *next;
}Node;

Node *criar(int valor){
    Node *novo = malloc(sizeof(Node));
    novo ->valor = valor;
    novo ->next = NULL;

    return novo;
}

void add(Node **head, int valor){
    Node *novo = criar(valor);

    if(*head ==NULL){
        *head = novo;
    } else{
        Node *aux = *head;

        while(aux ->next != NULL){
            aux = aux ->next;
        }

        aux ->next = novo;
    }
}

int contarPar(Node **head){
    int cont = 0;
    Node *aux = *head;

    while(aux != NULL){
        if(aux ->valor % 2 == 0){
            cont++;
        }
        aux = aux ->next;
    }

    return cont;
}

void imprimir(Node *head){
    if(head == NULL){
        return;
    } else{
        Node *aux = head;

        while(aux != NULL){
            printf("%d ", aux ->valor);
            aux = aux ->next;
        }
    }
}

int main() {
    Node *head = NULL;

    add(&head, 14);
    add(&head, 34);
    add(&head, 145);
    add(&head, 12);
    add(&head, 33);

    int r = contarPar(&head);
    printf("%d", r);
    
    return 0;
}