#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arq = fopen("contato.txt", "w");
    char nome[50];
    int idade;
    float altura;
    int opcao;

    if(arq){
        do {
            printf("Digite Nome, Idade e Altura: ");
            scanf("%49[^\n]%d%f", nome, &idade, &altura);

            fprintf(arq,"%s %d %.2f\n", nome, idade, altura);

            printf("Digite 1 para outro registro: ");
            scanf("%d", &opcao);
            getchar();
        } while(opcao == 1);

        fclose(arq);
    }
    return 0;
}