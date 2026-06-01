/*
    Implemente recursivamente a função int contaPares(int v[], int n) que recebe um vetor
    de n inteiros e retorna quantos elementos são pares. Não use laços.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contPar(int vet[], int i){
    if(i == 0) return 0;
    
    if(vet[i-1] % 2 == 0){
        return 1 + contPar(vet, i-1);
    } else{
        return 0 + contPar(vet, i-1);
    }
}

int main() {
    int n = 5;
    int vet[5] = {10,2,3,4,5};

    int r = contPar(vet, n);
    printf("Qtd de par: %d", r);
    return 0;
}