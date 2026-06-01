/*
    Usando a mesma estrutura da Q6, implemente recursivamente a função int somaLista(struct
    node *head) que retorna a soma de todos os valores da lista. Não use laços.
*/

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
    } else{
        Node *aux = *head;
        while(aux->next != NULL){
            aux = aux->next;
        }

        aux ->next = novo;
    }
}

int somaLista(Node *head){
    if(head == NULL) return 0;
    else return head ->valor + somaLista(head->next);
}

int main() {
    
    return 0;
}