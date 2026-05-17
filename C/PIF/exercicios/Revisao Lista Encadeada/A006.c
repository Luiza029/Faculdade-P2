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
    novo ->next = *head;
    *head = novo;
}

void substituir(Node *head, int x, int y){ // 10 20 30 10 50 ---> 10 - 90 = 
    Node *atual = head;

    while(atual != NULL){
        if(atual->valor == x){
            atual ->valor = y;
        }
            atual = atual->next;
    }
}

void imprimir(Node *head){
    if(head == NULL){
        return;
    } else{
        Node *aux = head;
        while(aux != NULL){
            printf("%d ", aux->valor);
            aux = aux ->next;
        }
    }
}

int main() {
    Node *head = NULL;

    add(&head, 10);
    add(&head, 20);
    add(&head, 30);
    add(&head, 10);
    add(&head, 10);

    printf("Lista Normal: ");
    imprimir(head);

    printf("\nDps: ");
    substituir(head, 10, 90);
    imprimir(head);
    
    return 0;
}