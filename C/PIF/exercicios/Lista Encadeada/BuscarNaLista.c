#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
}Node;

Node *criarLista(int valor){
    Node *novo = malloc(sizeof(Node));
    novo ->valor = valor;
    novo ->proximo = NULL;

    return novo;
}

Node *inserirFim(Node *head, int valor){
    Node *novo = criarLista(valor);
    
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

void Buscar(Node *head, int valorP){
    Node *aux = head;
    int achou = 0;

    while(aux != NULL){ // normal
        if(aux -> valor == valorP){
            printf("O numero %d esta na lista", valorP);
            achou = 1;
            break;
        }
        aux = aux ->proximo;
    }

    if(achou == 0)
        printf("O numero %d NAO esta na lista", valorP);
}

void Imprimir(Node *head){
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
    int i, n, valor, num;

    printf("Digite o tamanho da sua lista: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Digite: ");
        scanf("%d", &valor);
        head = inserirFim(head, valor);
    }

    printf("Digite o numero para buscar: ");
    scanf("%d", &num);
    Buscar(head, num);

    printf("\nSua Lista: ");
    Imprimir(head);

    return 0;
}