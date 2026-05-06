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

void addInicio(Node **head, int valor){
    Node *novo = criarLista(valor);
    novo ->proximo = *head;
    *head = novo;
}

Node *Busca(Node *head, int valor){
    if(head == NULL){
        printf("vazia");
    } else{
        Node *aux = head;
        while(aux != NULL){
            if(valor == aux -> valor){
                return aux;
            }

            aux = aux ->proximo;
        }
    }
    return NULL;
}

void Imprimir(Node **head){
    Node *aux = *head;

    while(aux != NULL){
        printf("%d ", aux -> valor);
        aux = aux -> proximo;
    }
}

int main() {
    Node *head = NULL;

    addInicio(&head, 10);
    addInicio(&head, 20);
    addInicio(&head, 30);

    Imprimir(&head);
    Node *r = Busca(head, 10);
    if(r != NULL){
        printf("\nAchou: %d", r->valor);
    } else{
        printf("\nValor nao encontrado!");
    }

    return 0;
}