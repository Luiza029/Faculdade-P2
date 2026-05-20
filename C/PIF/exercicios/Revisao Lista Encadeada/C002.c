#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *next;
}Node;

Node *criar(int valor){
    Node *novo = malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = NULL;

    return novo;
}

void add(Node **head, int valor){
    Node *novo = criar(valor);

    if(*head == NULL){
        *head = novo;
    }

    else{
        Node *aux = *head;
        while(aux->next != NULL){
            aux = aux->next;
        }

        aux->next = novo;
    }
}

void removerRepetidos(Node **head){ // 10 20 30 20 50
    Node *atual = *head;
    Node *aux = *head;
    Node *temp = NULL;
    
    while(atual != NULL){
        aux = atual;
        while(aux->next != NULL){
            if(atual->valor == aux->next->valor){
                temp = aux->next;
                aux->next = aux->next->next;
                free(temp);
            } else{
                aux = aux->next;
            }
        }
        atual = atual ->next;
    }
}

void imprimir(Node *head){
    
    if(head == NULL){
        return;
    } else{
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
    add(&head, 40);
    add(&head, 40);
    add(&head, 40);

    printf("Lista Normal: ");
    imprimir(head);

    printf("\nLista Nova: ");
    removerRepetidos(&head);
    imprimir(head);
    return 0;
}