#include <stdio.h>

typedef struct{
    int dia, mes, ano;
} Data; 

typedef struct{
    char nome[50];
    int tamanho;
} Arquivo;

int main() {
    
    Data data;
    Arquivo arquivo;

    printf("Digite uma data com dia, mes e ano: ");
    scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
    printf("Data: %d/%d/%d\n", data.dia, data.mes, data.ano);

    getchar();

    printf("Digite o nome do arquivo e o tamnho dele: ");
    scanf("%50[^\n] %d", arquivo.nome, &arquivo.tamanho);

    printf("Arquivo: %s \t| Tamanho: %d", arquivo.nome, arquivo.tamanho);

    return 0;
}