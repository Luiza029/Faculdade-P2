#include <stdio.h>

int produtoEscalar(int *vet1, int *vet2, int n){
    int i, soma = 0;

    for(i=0; i<n; i++){
        soma += *(vet1+i) * *(vet2+i);
    }

    return soma;
}

int main() {
    int n, i;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    int vet1[n], vet2[n];

    printf("Digite os valores do vetor 1: ");
    for(i=0; i<n; i++){
        scanf("%d", &vet1[i]);
    }

    printf("Digite os valores do vetor 2: ");
    for(i=0; i<n; i++){
        scanf("%d", &vet2[i]);
    }

    int r = produtoEscalar(vet1, vet2, n);
    printf("%d", r);
    return 0;
}