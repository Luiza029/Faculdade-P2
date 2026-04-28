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
            aux = aux ->proximo;
        }

        aux -> proximo = novo;
    }
    
    return head;
}

Node *remover(Node *head, int valorR){
    Node *aux = head;

    if(head -> valor == valorR){ // verifica se é para remover o proprio head
        return head -> proximo;
    }

    while(aux != NULL && aux -> proximo != NULL){
        if(aux -> proximo -> valor == valorR){
            aux -> proximo = aux -> proximo -> proximo; 
        }
        
        aux = aux -> proximo;
    }
    return head;
}

void imprimir(Node *head){
    Node *aux = head;
    while(aux != NULL){
        printf("%d ", aux -> valor);
        aux = aux -> proximo;
    }
}

int main() {
    Node *head = NULL;
    int valor, valorR, n, i;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Digite: ");
        scanf("%d", &valor);
        head = InserirFim(head, valor);
    }

    printf("Lista antes de remover: ");
    imprimir(head);

    printf("\nDigite um valor para ser removido: ");
    scanf("%d", &valorR);

    Node *r = remover(head, valorR);
    imprimir(r);

    return 0;
}