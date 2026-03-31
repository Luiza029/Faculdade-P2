#include <stdio.h>
int Vetor(int vet[], int n){
    int i, j, soma = 0, qtd = 0;

    for(i=1; i<n; i++){
        soma = 0;
        for(j=1; j<i; j++){
            soma += vet[j];
        }
        if(vet[i] > soma){
            qtd++;
        }
    }
    return qtd;
}

int main(){
    int vet[5] = {4,10,11,4,2}, n = 5;
    printf("Tiveram apenas %d elementos maiores que o anterior", Vetor(vet, n));
    return 0;
}