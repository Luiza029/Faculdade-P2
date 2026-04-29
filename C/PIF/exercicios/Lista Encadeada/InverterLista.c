#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
} Node;

Node *criarLista(int valor){
    Node *novo = malloc(sizeof(Node));
    novo -> valor = valor;
    novo -> proximo = NULL;

    return novo;
}

Node *InserirFim(Node *head, int valor){
    Node *novo = criarLista(valor);

    if(head == NULL){
        return novo;
    } else{
        Node *aux = head;

        while(aux -> proximo != NULL){
            aux = aux -> proximo;
        }

        aux -> proximo = novo;
        return head;
    }
}

Node *InverterLista(Node *head){
    Node *anterior = NULL;
    Node *atual = head;
    Node *proximo = NULL;

    while(atual != NULL){
        proximo = atual -> proximo;
        atual -> proximo = anterior;
        
        anterior = atual;
        atual = proximo;
    }

    return anterior;
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
    int n, valor, i;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Digite: ");
        scanf("%d", &valor);
        head = InserirFim(head, valor);
    }

    printf("Lista Normal: ");
    Imprimir(head);

    printf("\nLista Invertida: ");
    Node *r = InverterLista(head); // retorna um node!!!
    Imprimir(r);
    return 0;
}