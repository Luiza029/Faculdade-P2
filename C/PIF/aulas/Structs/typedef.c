#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// quando usa typedef, n precisa usar "struct Data data" na main, apenas "Data data"

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    int tamanho;

}Arquivo;

int main() {

    Data data;
    Arquivo arquivo;

    data.dia = 20;
    data.mes = 10;
    data.ano = 2006;

    printf("Data: %d/%d/%d", data.dia, data.mes, data.ano);

    strcpy(arquivo.nome, "Teste.txt"); // para passar strings, tem que usar funcao
    arquivo.tamanho = 350;

    printf("\tArquivo: %s \t| Tamanho: %d", arquivo.nome, arquivo.tamanho);


    return 0;
}