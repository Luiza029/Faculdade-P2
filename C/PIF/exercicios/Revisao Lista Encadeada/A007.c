#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *next;
}Node;

Node *criar(int valor){
    Node *novo  = malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = NULL;

    return novo;
}

void add(Node **head, int valor){
    Node *novo = criar(valor);

    if(*head == NULL){
        *head = novo;
    } else{
        Node *aux = *head;

        while(aux->next != NULL){
            aux = aux ->next;
        }

        aux ->next = novo;
    }
}

void imprimir(Node *head){
    if(head == NULL){
        return;
    } else{
        Node *aux = head;

        while(aux != NULL){
            printf("%d ", aux->valor);
            aux = aux ->next;
        }
    }
}

int main() {
    Node *head = NULL; 
    return 0;
}