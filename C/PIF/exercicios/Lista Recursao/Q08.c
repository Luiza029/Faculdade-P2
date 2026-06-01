/*
    Usando a mesma estrutura da Q6, implemente recursivamente a função int
    buscaLista(struct node *head, int x) que retorna 1 se x estiver na lista e 0 caso
    contrário. Não use laços.
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
        aux->next = novo;
    }
}

int buscarLista(Node *head, int x){
    if(head == NULL) return 0;

    if(head->valor == x) return 1;
    else return buscarLista(head->next, x);
}

int main() {
    
    return 0;
}