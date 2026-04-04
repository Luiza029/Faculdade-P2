#include <stdio.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    int tamanho;
    Data criacao, edicao;
} Arquivo;

int main() {
    Arquivo arquivo;

    printf("Digite o nome do arquivo: ");
    scanf("%50[^\n]", arquivo.nome);
    arquivo.tamanho = 412;
    arquivo.criacao.dia = 12;
    arquivo.criacao.mes = 12;
    arquivo.criacao.ano = 2003;

    arquivo.edicao.dia = 23;
    arquivo.edicao.mes = 1;
    arquivo.edicao.ano = 2004;

    printf("Arquivo: %s \t|\t Tamanho: %d\n", arquivo.nome, arquivo.tamanho);

    printf("Criacao: %d/%d/%d\n", arquivo.criacao.dia, arquivo.criacao.mes, arquivo.criacao.ano);

    printf("Edicao: %d/%d/%d\n", arquivo.edicao.dia, arquivo.edicao.mes, arquivo.edicao.ano);

    return 0;
}