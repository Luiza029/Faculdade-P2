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

void add(Node **head, int valor){
    Node *novo = criarLista(valor);

    if(*head == NULL){
        *head = novo;
    } 
    else{
        Node *aux = *head;

        while(aux -> proximo != NULL){
            aux = aux ->proximo;
        }

        aux ->proximo = novo;
    }
}

void removerUltimo(Node **head){
    if(*head == NULL){
        return;
    } else if((*head) ->proximo == NULL){
        free(*head);
        *head = NULL;
    } else{ 
        Node *aux = *head;

        while(aux -> proximo ->proximo != NULL){ // 10 20 30 40 aux ->proximo -> proximo, eu paro no 30, pois se eu usar o aux -> proximo eu paro no 40, e 40 é o no que eu quero remover 
            aux = aux -> proximo;
        }

        free(aux -> proximo); // libera o ultimo no
        aux ->proximo = NULL;
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

    add(&head, 10);
    add(&head, 20);
    add(&head, 60);
    add(&head, 40);
    add(&head, 50);
    add(&head, 11);
    
    printf("Lista antes de remover: ");
    imprimir(&head);

    printf("\nDps de remover o ultimo: ");
    removerUltimo(&head);
    imprimir(&head);
    
    return 0;
}