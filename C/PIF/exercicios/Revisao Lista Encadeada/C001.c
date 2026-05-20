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
    }

    else{
        Node *aux = *head;
        while(aux->next != NULL){
            aux = aux->next;
        }

        aux->next = novo;
    }
}

void inserirPosicao(Node **head, int pos, int x){ // 10 20 X 40 50
    Node *atual = *head;
    Node *novo = criar(x);
    int cont = 0;

    while(atual != NULL && cont != pos - 1){
        atual = atual->next;
        cont++;
    }

    novo->next = atual->next;
    atual->next = novo;
}

void imprimir(Node *head){
    
    if(head == NULL){
        return;
    } else{
        Node *aux = head;
        while(aux != NULL){
            printf("%d ", aux->valor);
            aux = aux->next;
        }
    }
}

int main() {
    Node *head = NULL;

    add(&head, 10);
    add(&head, 20);
    add(&head, 30);
    add(&head, 40);
    add(&head, 50);

    printf("Lista Normal: ");
    imprimir(head);

    printf("\nLista Nova: ");
    inserirPosicao(&head, 1, 90);
    imprimir(head);
    return 0;
}