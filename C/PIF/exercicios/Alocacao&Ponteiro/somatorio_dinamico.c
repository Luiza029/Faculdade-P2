#include <stdio.h>
#include <stdlib.h>

int* alocM(int n){ // vai alocar as memorias
    int *x = malloc(n * sizeof(int));
    return x;
}

void preencher(int *vet, int n){
    for(int i=0; i<n; i++) *(vet+i) = i;
}

void imprimir(int *vet, int n){
    for(int i=0; i<n; i++) printf("%d ", *(vet+i));
}

int soma(int *vet, int n){
    int soma = 0;
    for(int i=0; i<n; i++) soma += *(vet+i);

    return soma;
}

int main() {
    int *vet, n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vet = alocM(n);

    if(vet){
        preencher(vet, n);
        imprimir(vet, n);
        printf("\nSoma: %d", soma(vet, n));
    } else{
        printf("Erro ao alocar memoria!");
    }

    return 0;
}