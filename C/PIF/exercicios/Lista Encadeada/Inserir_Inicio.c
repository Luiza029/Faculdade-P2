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

Node *InserirInicio(int valor, Node *head){
    Node *novo = criarLista(valor);
    novo -> proximo = head;

    return novo;
}

void imprimir(Node *head){
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
        head = InserirInicio(valor, head);
    }

    printf("Sua Lista: ");
    imprimir(head);
    return 0;
}