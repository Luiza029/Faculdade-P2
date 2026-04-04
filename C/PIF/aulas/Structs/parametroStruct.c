#include <stdio.h>

typedef struct{
    int dia, mes, ano;
} Data;

typedef struct{
    char nome[100];
    int tamanho;
} Arquivo;

void imprimirData(Data data){
    printf("===> Data: %d/%d/%d\n", data.dia, data.mes, data.ano);
}

void imprimirArquivo(Arquivo arq){
    printf("===> Arquivo: %s \t|\t Tamanho: %d", arq.nome, arq.tamanho); // tem que renomear de acordo com o parametro
}

int main() {
    
    Data data;
    Arquivo arquivo;

    printf("Digite uma data com dia, mes e ano: ");
    scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
    imprimirData(data);

    getchar();

    printf("Digite o nome do arquivo: ");
    scanf("%100[^\n]", arquivo.nome);
    printf("Digite o tamanho: ");
    scanf("%d", &arquivo.tamanho);

    imprimirArquivo(arquivo);

    return 0;
}