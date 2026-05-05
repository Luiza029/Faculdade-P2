#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
} Node;

void Inicializar_lista(Node **head){
    *head = NULL;
}

int main() {
    Node *head = NULL;

    Inicializar_lista(&head);

    if(head == NULL){
        printf("Lista inicializada com sucesso");
    }
    return 0;
}