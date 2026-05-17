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

void removerTodos(Node **head, int valor){ // 10 20 30 10 40
    Node *atual;
    Node *temp;

    if(*head == NULL){
        return;
    }

    while(*head != NULL && (*head)->valor == valor){
        temp = *head;
        *head = (*head) ->next;
        free(temp);
    }

    atual = *head;
    while(atual != NULL && atual->next != NULL){
        if(atual->next->valor == valor){
            temp = atual ->next;
            atual ->next = atual ->next->next;
            free(temp);
        }

        else{
            atual = atual->next;
        }
    }
}

void imprimir(Node *head){
    if(head == NULL){
        return;
    }

    else{
        Node *aux = head;

        while(aux != NULL){
            printf("%d ", aux->valor);
            aux = aux->next;
        }
    }
}

int main() {
    Node *head = NULL;

    add(&head, 10);
    add(&head, 20);
    add(&head, 30);
    add(&head, 20);
    add(&head, 10);

    printf("Lista Normal: ");
    imprimir(head);

    printf("\nDps: ");
    removerTodos(&head, 10);
    imprimir(head);
    return 0;
}