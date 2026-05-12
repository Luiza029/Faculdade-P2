#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
}Node;

Node *criar(int valor){
    Node *novo = malloc(sizeof(Node));
    novo ->valor = valor;
    
}

void add(Node **head, int valor){
    Node *novo = criar(valor);

    if(*head == NULL){
        *head = novo;
    }else{
        Node *aux = *head;
        Node *anterior = *head;

        while(aux != NULL && aux ->valor < valor){
            anterior = aux;
            aux = aux ->proximo;
        }

        anterior ->proximo = novo;
        novo ->proximo = aux;
    }
}

void inverter(Node **head){
    if(*head == NULL){
        printf("Lista vazia");
    } else{
        Node *atual = *head;
        Node *prox = NULL;
        Node *anterior = NULL;

        while(atual != NULL){
            prox = atual ->proximo; // salvando o atual
            atual ->proximo = anterior;
            anterior = atual;
            atual = prox;
        }

        *head = anterior;
    }
}

int main() {
    
    return 0;
}