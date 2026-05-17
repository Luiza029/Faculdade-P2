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

    if(*head == NULL){
        *head = novo;
    } 

    else{
        Node *aux = *head;

        while(aux ->next != NULL){
            aux = aux->next;
        }

        aux ->next = novo;
    }
}

Node* encontrarNo(Node *head){ // 10 20 30 40
    Node *lento = head;
    Node *rapido = head;

    while(rapido != NULL && rapido ->next != NULL){
        lento = lento->next;
        rapido = rapido ->next->next;
    }

    return lento;
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

    add(&head, 10);
    add(&head, 20);
    add(&head, 30);
    add(&head, 40);
    add(&head, 50);
    add(&head, 60);

    imprimir(head);
    printf("\n");
    
    Node* resultado = encontrarNo(head);
    printf("Valor do meio: %d", resultado->valor);

    return 0;
}