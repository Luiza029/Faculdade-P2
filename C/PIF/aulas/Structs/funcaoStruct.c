#include <stdio.h>

typedef struct{
    int dia, mes, ano;
} Data;

typedef struct{
    char nome[100];
    int tamanho;
} Arquivo;

Data preencherData(){
    Data data;
    printf("Digite uma data com dia, mes e ano: ");
    scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
    return data;
}

Arquivo preencherArquivo(){
    Arquivo arquivo;

    printf("Digite o nome do arquivo: ");
    scanf("%100[^\n]", arquivo.nome);
    printf("Digite o tamanho: ");
    scanf("%d", &arquivo.tamanho);

    return arquivo;
}

void imprimirData(Data data){
    printf("Data: %d/%d/%d\n", data.dia, data.mes, data.ano);
}

void imprimirArquivo(Arquivo arq){
    printf("Arquivo: %s \t|\t Tamanho: %d", arq.nome, arq.tamanho);
}

int main() {
    
    Data data;
    Arquivo arquivo;

    data = preencherData(data);
    imprimirData(data);

    getchar();

    arquivo= preencherArquivo(arquivo);
    imprimirArquivo(arquivo);

    return 0;
}