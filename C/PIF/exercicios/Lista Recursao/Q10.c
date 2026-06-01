/*
    Escreva um programa em C que leia um arquivo de texto chamado numeros.txt contendo um
    inteiro por linha, armazene os valores em uma lista encadeada e, usando uma função recursiva,
    grave em um novo arquivo invertido.txt os mesmos valores na ordem inversa (do último para
    o primeiro nó da lista). Você pode assumir que o arquivo existe e tem no máximo 100 linhas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *next;
}Node;

Node *criar(int valor){
    Node *novo = malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = NULL;

    return novo;
}

void addNum(Node **head, int valor){
    Node *novo = criar(valor);
    
    if(*head == NULL){
        *head = novo;
    } else{
        Node *aux = *head;
        while(aux->next != NULL){
            aux = aux->next;
        }

        aux->next = novo;
    }
}

void inverter(Node *head, FILE *arq){
    if(head == NULL) return;
    
    inverter(head->next, arq);
    fprintf(arq, "%d\n", head->valor);
}

int main() {
    int num;
    Node *head = NULL;

    FILE *arq = fopen("numeros.txt", "r");
    while(fscanf(arq, "%d", &num) == 1){
        addNum(&head, num);
    }

    FILE *saida = fopen("invertido.txt", "w");
    inverter(head, saida);
    fclose(saida);
    return 0;
}