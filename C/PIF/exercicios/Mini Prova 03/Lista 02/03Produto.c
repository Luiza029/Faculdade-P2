#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int buscar_produto_mais_caro(Produto vet[], int n){
    int indice = 0, i;
    float maior = vet[0].preco;

    for(i=0; i<n; i++){
        float maiorAtual = vet[i].preco;
        if(maiorAtual > maior){
            maior = maiorAtual;
            indice = i;
        }
    }

    return indice;
}

int main() {
    int n, i;

    printf("Digite a qtd de produto que existem: ");
    scanf("%d", &n);

    Produto vetP[n];

    for(i=0; i<n; i++){
        printf("Digite o nome do %d produto: ", i+1);
        scanf(" %49[^\n]", vetP[i].nome);

        printf("Digite o preco do %d produto: ", i+1);
        scanf("%f", &vetP[i].preco);

        printf("Digite a qtd do %d produto: ", i+1);
        scanf("%d", &vetP[i].quantidade);
    }

    int r = buscar_produto_mais_caro(vetP, n);

    printf("Produto mais caro: %s\n", vetP[r].nome);
    printf("Preco: R$ %.2f\n", vetP[r].preco);
    printf("Qtd: %d\n",vetP[r].quantidade);
    return 0;
}