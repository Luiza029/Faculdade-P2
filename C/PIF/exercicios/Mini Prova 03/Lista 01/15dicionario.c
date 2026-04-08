#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, tam = 0;
    char **lista, nome[50];

    printf("Digite o tamanho de N: ");
    scanf("%d", &n);

    lista = (char**) malloc(n * sizeof(char*));

    for(i=0; i<n; i++){
        printf("Digite um nome: ");
        scanf(" %49[^\n]", nome);

        tam = strlen(nome) + 1; // +1 para pegar o \0
        lista[i] = (char*) malloc(tam * sizeof(char));
        strcpy(lista[i], nome);
    }

    for(i=0; i<n; i++){
        printf("%s ", lista[i]);
    }

    for(i=0; i<n; i++){
        free(lista[i]);
    }

    free(lista);
    return 0;
}