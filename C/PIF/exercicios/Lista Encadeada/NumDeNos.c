#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
}Node;

Node *CriarLista(int valor){
    Node *novo = malloc(sizeof(Node));
    novo -> valor = valor;
    novo -> proximo = NULL;

    return novo;
}

Node *InserirFim(Node *head, int valor){
    Node *novo = CriarLista(valor);

    if(head == NULL){
        return novo;
    } else{
        Node *aux = head;

        while(aux -> proximo != NULL){
            aux = aux -> proximo;
        }

        aux -> proximo = novo;
    }

    return head;
}

int Contador(Node *head){
    Node *aux = head;
    int cont = 0;

    while(aux != NULL){
        cont++;
        aux = aux -> proximo;
    }

    return cont;
}

void Imprimir(Node *head){
    Node *aux = head;

    while(aux != NULL){
        printf("%d ", aux -> valor);
        aux = aux -> proximo;
    }
}

int main() {
    Node *head = NULL;
    int valor;

    printf("Digite: ");
    scanf("%d", &valor);

    while(valor != 0){
        printf("Digite: ");
        scanf("%d", &valor);
        if(valor != 0)
            head = InserirFim(head, valor);
    }
    
    printf("Sua Lista:");
    Imprimir(head);
    
    int r = Contador(head);
    printf("\nTamanho da sua lista: %d", r);

    return 0;
}