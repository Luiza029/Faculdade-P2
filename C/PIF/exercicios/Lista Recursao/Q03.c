/*
    Implemente recursivamente a função int estaNoVetor(int v[], int n, int x) que
    retorna 1 se x estiver em v e 0 caso contrário. Não use laços.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int estaNoVetor(int vet[], int i, int x){
    if(i == 0) return 0;

    if(vet[i-1] == x){
        return 1;
    } else{
        return estaNoVetor(vet, i-1, x);
    }
}

int main() {
    int n = 5;
    int vet[5] = {2,4,6,3,3};
    int x = 3;

    int r = estaNoVetor(vet, n, x);
    printf("%d", r);
    return 0;
}