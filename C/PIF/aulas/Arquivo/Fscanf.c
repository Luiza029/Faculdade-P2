#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arq = fopen("contato.txt", "r");
    char nome[50];
    int idade;
    float altura;

    if(arq){
        while(fscanf(arq, "%s%d%f", nome, &idade, &altura) != -1){
            printf("Nome: %s \t|\t Idade: %d \t|\t Altura: %.2f\n", nome, idade, altura);
        }
        fclose(arq);
    }
    return 0;
}