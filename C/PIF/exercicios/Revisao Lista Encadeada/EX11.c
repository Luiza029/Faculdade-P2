#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
}Node;

Node *Criar(int valor){
    Node *novo = malloc(sizeof(Node));

    novo -> valor = valor;
    novo -> proximo = NULL;

    return novo;
}

void add(Node **head, int valor){
    Node *novo = Criar(valor);

    if(*head == NULL){
        *head = novo;
    } else{
        Node *aux = *head;

        while(aux ->proximo != NULL){
            aux = aux -> proximo;
        }

        aux ->proximo = novo;
    }
}

void removerNo(Node **head, int valor){ //10 20 30 40 50
    if(*head == NULL){
        return;
    } else{
        Node *aux = *head;

        while(aux ->proximo != NULL && aux -> proximo ->valor != valor){
            aux = aux -> proximo;
        }

        free(aux ->proximo); // primeiro pois pode perder o endereco do 40
        aux ->proximo = aux ->proximo ->proximo; // aux -> proximo: que esta parado no nó 30, pega o endereço do 40 (nao o valor), e aux -> proximo -> proximo, pega o endereco de 50
    }
}

void imprimir(Node **head){
    if(*head != NULL){
        Node *aux = *head;

        while(aux != NULL){
            printf("%d ", aux ->valor);
            aux = aux -> proximo;
        }
    } else{
        printf("Lista vazia");
    }
}

int main() {

    Node *head = NULL;

    add(&head, 10);
    add(&head, 20);
    add(&head, 30);
    add(&head, 40);
    add(&head, 50);

    imprimir(&head);
    removerNo(&head, 40);
    printf("\n");
    imprimir(&head);
    
    return 0;
}