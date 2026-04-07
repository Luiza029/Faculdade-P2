#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
} Pessoa;

int main() {
    Pessoa *p1;

    p1 = (Pessoa*)malloc(1 * sizeof(Pessoa));

    scanf("%s", p1->nome);
    scanf("%d", p1->idade);

    printf("%s\n", p1->nome);
    printf("%d", p1->idade);

    free(p1);
    p1 = NULL;
    return 0;
}