#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
} Node;

Node* CriarNo(int valor){
    Node *novo = malloc(sizeof(Node));

    novo -> valor = valor;
    novo -> proximo = NULL;

    return novo;
}

void imprimirLista(Node *head){
    if(head){
        Node *aux = head; // a variavel aux vai receber o inicio

        while(aux != NULL){
            printf("%d ", aux -> valor);
            aux = aux -> proximo;
        }
    }
}

Node *inserirInicio(Node *head, int valor){
    Node *novo = CriarNo(valor);
    novo -> proximo = head; // o head aponta para o ultimo digitado (na logica de inserir um elemento)

    return novo;
}

int main() {
    
    Node *head = NULL;
    int n, valor;

    printf("Digite o tamanho de lista: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Digite o %d numero: ", i+1);
        scanf("%d", &valor);
        head = inserirInicio(head, valor);
    }

    printf("Sua lista: ");
    imprimirLista(head);     

    return 0;
}