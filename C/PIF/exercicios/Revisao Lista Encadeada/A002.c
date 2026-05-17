#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
}Node;

Node *criar(int valor){
    Node *novo = malloc(sizeof(Node));
    novo->valor = valor;
    novo->proximo = NULL;

    return novo;
}

void *add(Node **head, int valor){
    Node *novo = criar(valor);

    if(*head == NULL){
        *head = novo;
    } else{
        Node *aux = *head;

        while(aux ->proximo != NULL){
            aux = aux ->proximo;
        }

        aux->proximo = novo;
    }
}

void removerRepetidos(Node **head){ // 10 20 20 20 30 40 50
    Node *atual = *head;
    Node *temp = *head;

    while(atual ->proximo != NULL){
        if(atual -> valor == atual ->proximo -> valor){
            temp = atual ->proximo; // guarda o no do segundo 20
            atual ->proximo = atual ->proximo->proximo; // atual->proximo é o primeiro 20 e atual->proximo->proximo pula para o terceiro 20
            free(temp);
        } 
        else{
            atual = atual ->proximo;
        }
    }
}

void imprimir(Node *head){
    if(head == NULL){
        return;
    } else{
        Node *aux = head;
        
        while(aux != NULL){
            printf("%d ", aux->valor);
            aux = aux->proximo;
        }
    }
}

int main() {
    Node *head = NULL;

    add(&head, 10);
    add(&head, 20);
    add(&head, 20);
    add(&head, 20);
    add(&head, 30);
    add(&head, 40);
    add(&head, 50);

    printf("Antes de remover repetidos: ");
    imprimir(head);

    printf("\n");

    printf("Depois de remover repetidos: ");
    removerRepetidos(&head);
    imprimir(head);
    return 0;
}