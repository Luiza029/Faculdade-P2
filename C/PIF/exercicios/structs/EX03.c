#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
} Pessoa;


Pessoa* criaPessoa(char* nome, int idade){
    Pessoa* temp = (Pessoa*) malloc(sizeof(Pessoa));
    if(temp != NULL){
        strcpy(temp->nome, nome);
        temp->idade = idade;
    }

    return temp;
}

int main() {
    Pessoa *p = criaPessoa("Fulano", 20);
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d", p->idade);
    return 0;
}