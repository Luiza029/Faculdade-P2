#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

Node* CreateNode(int valor){
    Node* temp = (Node*) malloc(sizeof(Node));

    temp -> valor = valor;
    temp -> next = NULL;

    return temp;
}

void add(Node** head, int valor){
    if(*head == NULL)
        *head = CreateNode(valor);
    else
        (*head) -> next = CreateNode(valor);
}

int main() {

    Node* head = NULL;
    add(&head, 10);
    add(&head, 10);
    add(&head, 10);

    Node* temp = head;

    while(temp != NULL){
        printf("%d ", head -> valor);
        temp = temp -> next;
    }
    return 0;
}