#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
} Node;

Node *CriarLista(int valor){
    Node *novo = malloc(sizeof(Node));
    novo -> valor = valor;
    novo -> proximo = NULL;

    return novo;
}

// a funcao sendo um void
void inserirFinal(Node **head, int valor){
    Node *novo = CriarLista(valor);

    if(*head == NULL){
        return novo;
    } else{
        Node *aux = *head;

        while(aux -> proximo != NULL){
            aux = aux -> proximo;
        }

        aux -> proximo = novo;
    }
}

void imprimirLista(Node *head){
    if(head){
        Node *aux = head;

        while(aux != NULL){
            printf("%d ", aux -> valor);
            aux = aux -> proximo;
        }
    }
}

int main() {
    Node *head = NULL;
    int i, n, valor;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Digite: ");
        scanf("%d", &valor);
        inserirFinal(&head, valor);
    }

    printf("Sua Lista: ");
    imprimirLista(head);
    return 0;
}