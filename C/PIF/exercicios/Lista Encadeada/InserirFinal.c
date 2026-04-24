#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
}Node;

Node *CriarNo(int valor){
    Node *novo = malloc(sizeof(Node)); // toda vez que for criar uma funcao para criar um no, faz o malloc

    novo -> valor = valor;
    novo -> proximo = NULL;

    return novo;
}

Node *inserirFim(Node *head, int valor){
    Node *novo = CriarNo(valor);

    if(head == NULL){
        return novo;
    }
        Node *aux = head;

        while(aux ->proximo != NULL){
            aux = aux -> proximo;
        }

        aux -> proximo = novo;

        return head;
}

void ImprimirLista(Node *head){
    if(head){
        Node *aux = head;

        while(aux != NULL){
            printf("%d ", aux ->valor);
            aux = aux -> proximo;
        }
    } else{
        printf("Nao foi possivel alocar memoria");
    }
}

int main() {
    
    Node *head = NULL;
    int n, valor;

    printf("Digite o tamanho da sua lista: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Digite: ");
        scanf("%d", &valor);
        head = inserirFim(head, valor);
    }


    printf("Lista: ");
    ImprimirLista(head);

    return 0;
}