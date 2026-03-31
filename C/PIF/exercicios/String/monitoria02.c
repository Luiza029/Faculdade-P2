#include <stdio.h>

void qtd(int *vet, int n, int *qtdPositivo, int *qtdNegativo, int *qtdZero){
    int i;

    for(i=0; i<n; i++){
        if(*(vet+i) > 0){
            (*qtdPositivo)++;
        }else if(*(vet+i) < 0){
            (*qtdNegativo)++;
        }else{
            (*qtdZero)++;
        }
    }    
}

int main() {
    int n, i;
    int qtdNegativo = 0, qtdPositivo = 0, qtdZero = 0;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    int vet[n];

    printf("Digite os valores do vetor 1: ");
    for(i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }


    qtd(vet, n, &qtdPositivo, &qtdNegativo, &qtdZero);

    printf("Qtd de Positivo: %d\n", qtdPositivo);
    printf("Qtd de Positivo: %d\n", qtdNegativo);
    printf("Qtd de Positivo: %d\n", qtdZero);
    return 0;
}