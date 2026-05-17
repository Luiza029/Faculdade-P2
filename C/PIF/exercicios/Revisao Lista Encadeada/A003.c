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
    novo->next = NULL;

    return novo;
}

void add(Node **head, int valor){
    Node *novo = criar(valor);
    novo ->next = *head;
    *head = novo;
}

void inserirPosicao(Node **head, int valor, int pos){ // 10 20 30 x 50
    Node *novo = criar(valor);
    Node *atual = *head;
    int cont = 0;

    while(atual != NULL && cont != pos - 1){
        atual = atual->next;
        cont++;
    }

    novo->next = atual ->next; 
    atual ->next = novo;
}

void imprimir(Node *head){
    if(head == NULL){
        return;
    }else{
        Node *aux = head;
        while(aux != NULL){
            printf("%d ", aux->valor);
            aux = aux->next;
        }
    }
}

int main() {
    Node *head = NULL;

    add(&head,10);
    add(&head,20);
    add(&head,30);
    add(&head,50);
    
    inserirPosicao(&head, 40, 1);
    imprimir(head);
    return 0;
}