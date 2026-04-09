#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    float preco;
} Produto;

typedef struct{
    Produto itens[5];
    int quantidade;
} Pedido;

float valor_total_pedido(Pedido p){
    int i;
    float total = 0;

    for(i=0; i<p.quantidade; i++){
        total += p.itens[i].preco;
    }

    return total;
}


int pedido_mais_caro(Pedido v[], int n){
    int i, indice = 0;
    float maisCaro = valor_total_pedido(v[0]);

    for(i=0 ; i<n; i++){
        float pedidoAtual = valor_total_pedido(v[i]);

        if(pedidoAtual > maisCaro){
            maisCaro = pedidoAtual;
            indice = i;
        }
    }

    return indice;
}

int main() {
    int n, i, j;

    printf("Digite o valor de N: ");
    scanf("%d", &n);

    Pedido vetP[n];

    for(i=0; i<n; i++){
        printf("Digite a quantidade: ");
        scanf("%d", &vetP[i].quantidade);

        for(j=0; j<vetP[i].quantidade; j++){
            printf("Produto %d:\n", j+1);

            printf("Digite o nome do produto: ");
            scanf(" %49[^\n]", vetP[i].itens[j].nome);

            printf("Digite o preco do produto: ");
            scanf("%f", &vetP[i].itens[j].preco);
        }
    }

    int r = pedido_mais_caro(vetP, n);
    float total = valor_total_pedido(vetP[r]);

    printf("Maior Pedido: R$ %.2f\n", total);

    return 0;
}