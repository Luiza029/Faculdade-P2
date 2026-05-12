#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *proximo;
} Node;

Node *criar(int valor){
    Node *novo = malloc(sizeof(Node));
    novo ->valor = valor;
    novo ->proximo = NULL;

    return novo;
}

void addFim(Node **head, int valor){
    Node *novo = criar(valor);

    if(*head == NULL){
        *head = novo;
    } else{
        Node *aux = *head;

        while(aux ->proximo != NULL){
            aux = aux->proximo;
        }

        aux ->proximo = novo;
    }
}

void addInicio(Node **head, int valor){
    Node *novo = criar(valor);
    novo ->proximo = *head;
    *head = novo;
}

void removerDuplicado(Node **head){ //10 20 30 20 40
    if(*head == NULL){
        return;
    
    } else if((*head)->proximo ==NULL){
        printf("A lista so tem um numero");
    
    }else{
        Node *aux = *head;
        Node *atual = *head;
        Node *temp = NULL;

        while(atual != NULL){
            aux = atual;
            while(aux->proximo != NULL){
                if(atual->valor == aux->proximo->valor){
                    temp = aux ->proximo;
                    aux ->proximo = aux->proximo->proximo;
                    free(temp); 
                } else{
                    aux = aux->proximo;
                }
            }
            atual = atual ->proximo;
        }
    }
}

void imprimir(Node **head){
    if(*head == NULL){
        return;
    } else{
        Node *aux = *head;
        while(aux != NULL){
            printf("%d ", aux ->valor);
            aux = aux ->proximo;
        }
    }
}

int main() {
    Node *head = NULL;
    char digitado;
    int valor;

    do{
        printf("[F] Inserir Fim\n");
        printf("[I] Inserir Inicio\n");
        printf("[T] Terminar\n");
        scanf(" %c", &digitado);

      if(digitado == 'F'){
        printf("Digite o valor para inserir no fim: ");
        scanf("%d", &valor);
        addFim(&head, valor);
      } 
      
      else if(digitado == 'I'){
        printf("Digite o valor para inserir no Inicio: ");
        scanf("%d", &valor);
        addInicio(&head, valor);
      }


    } while (digitado != 'T');
    
    printf("Antes de remover repetidos: ");
    imprimir(&head);
    
    printf("\nDps: ");
    removerDuplicado(&head);
    imprimir(&head);
    return 0;
}