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
    } else{
        Node *aux = *head;
        
        while(aux -> proximo != NULL){
            aux = aux -> proximo;
        }

        aux ->proximo = novo;
    }
}

void freeLista(Node **head){
    if(*head == NULL){
        return;
    } else{
        Node *aux = *head;
        
        while(aux != NULL){
            Node *temp = aux; // salva o no atual
            aux = aux ->proximo; // avanca 
            free(temp); // da free
        }
        
        *head = NULL;
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
    freeLista(&head);
    printf("\n");
    imprimir(&head);
    
    return 0;
}