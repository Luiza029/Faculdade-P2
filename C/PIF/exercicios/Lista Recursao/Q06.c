/*
    Dada a estrutura:
        struct node { int valor; struct node *next; };
    Implemente recursivamente a função int tamanho(struct node *head) que retorna o
    número de nós da lista. Não use laços.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

Node *criarNo(int valor){
    Node *novo = malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = NULL;

    return novo;
}

void ADD(Node **head, int valor){
    Node *novo = criarNo(valor);
    if(*head == NULL){
        *head = novo;
    } else{
        Node *aux = *head;
        while(aux->next != NULL){
            aux = aux->next;
        }

        aux->next = novo;
    }
}

int tamanho(Node *head){
    if(head == NULL) return 0;
    
    else return 1 + tamanho(head->next);
}

int main() {
        
    return 0;
}