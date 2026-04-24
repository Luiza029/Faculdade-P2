#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
}Node;

Node *CriarNode(int valor){
    Node *novo = malloc(sizeof(Node));
    novo -> valor = valor;
    novo ->proximo = NULL;

    return novo;
}

Node *InserirInicio(Node *head, int valor){
    Node *novo = CriarNode(valor);
    novo -> proximo = head;

    return novo;
}

int Pesquisar(Node *head, int valorP){
    Node *aux = head;
    int achou = 0;

    while(aux != NULL){
        if(aux -> valor == valorP){
            printf("O valor digitado foi encontrado na lista!");
            achou = 1;
            break;
        }
        aux = aux -> proximo;
    }
    
    if(achou == 0){
        printf("Nao foi possivel achar o numero");
    }
    
    return achou;
}

int main() {
    Node *head = NULL;
    int i, valor, n, valorP;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Digite: ");
        scanf("%d", &valor);

        head = InserirInicio(head, valor);
    }

    printf("Digite o numero quer pesquisar: ");
    scanf("%d", &valorP);

    Pesquisar(head, valorP);

    return 0;
}