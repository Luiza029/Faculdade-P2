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

Node *inserirFim(Node *head, int valor){
    Node *novo = CriarLista(valor);

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

Node *InserirNaPosicao(Node *head, int valorP, int posicao){
    Node *aux = head;
    Node *novo = CriarLista(valorP);
    int cont = 0;

    while(cont != posicao && aux != NULL){
        cont ++;
        aux = aux -> proximo;
    }
    
    if(aux != NULL)
        novo -> proximo = aux -> proximo;
    aux -> proximo = novo;

    return head;
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
    int n, valor, posicao, valor2;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Digite: ");
        scanf("%d", &valor);
        head = inserirFim(head, valor);
    }

    printf("Sua lista: ");
    imprimir(head);

    printf("\nDigite um valor e sua posisao: ");
    scanf("%d %d", &valor2, &posicao);

    head = InserirNaPosicao(head, valor2, posicao);
    imprimir(head);

    return 0;
}