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
            aux = aux->proximo;
        }

        aux->proximo = novo;
    }
}

int Maior_valor(Node **head){

    if(*head == NULL){
        return -9999;
    } else{
        int maior = (*head) ->valor; // pega o primeiro valor
        Node *aux = (*head) ->proximo; // pega o segundo valor

        while(aux != NULL){
            if(aux ->valor > maior){
                maior = aux->valor;
            }

            aux = aux ->proximo;
        }

        return maior;
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
    
    imprimir(&head);
    int r = Maior_valor(&head);

    printf("\nMaior: %d", r);

    return 0;
}