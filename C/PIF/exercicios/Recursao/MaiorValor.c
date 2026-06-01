#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MaiorValor(int vet[], int i){
    if(i == 0){
        return vet[0];
    } 

    int maior = MaiorValor(vet, i - 1);

    if(vet[i-1] > maior)
        return vet[i-1];
    else
        return maior;
}

int MaiorValor2(int maior, int vet[], int i){
    if(i == 0)
        return maior;
    if(vet[i-1] > maior)
        maior = vet[i-1];
    return MaiorValor2(maior, vet, i);
}

int main() {
    int i = 5;
    int maior = 0;
    int vet[5] = {7,3,2,5,6};

    int r = MaiorValor(vet, i);
    printf("O maior valor eh: %d", r);

    int q = MaiorValor2(maior, vet, i);
    printf("O maior valor eh: %d", q);

    return 0;
}