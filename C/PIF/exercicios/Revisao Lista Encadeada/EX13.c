#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *next;
}Node;

Node *criar(int valor){
    Node *novo = malloc(sizeof(Node));
    novo ->valor = valor;
    novo ->next = NULL;

    return novo;
}

void add(Node **head, int valor){
    Node *novo = criar(valor);
    novo ->next = *head;
    *head = novo;
}

Node *mesclarar(Node *l1, Node *l2){ // 1 3 5 7 || 2 4 6 8
    Node *head = criar(l1 ->valor);
    Node *aux = head;
    l1 = l1->next;

    while(l1 != NULL || l2 != NULL){
        if(l2 != NULL){
            aux->next = criar(l2->valor);
            aux = aux->next;
            l2 = l2->next;
        }

        if(l1 != NULL){
            aux->next = criar(l1->valor);
            aux = aux ->next;
            l1 = l1->next;
        }
    }
    return head;
}

void imprimir(Node *head){
    if(head == NULL){
        return;
    }

    else{
        Node *aux = head;
        while(aux != NULL){
            printf("%d ", aux->valor);
            aux = aux->next;
        }
    }
}

int main() {
    Node *l1 = NULL, *l2 = NULL, *resultado = NULL;

    add(&l1, 10);
    add(&l1, 30);
    add(&l1, 50);
    add(&l1, 70);

    add(&l2, 20);
    add(&l2, 40);
    add(&l2, 60);
    add(&l2, 80);

    resultado = mesclarar(l1, l2);
    imprimir(resultado);

    return 0;
}