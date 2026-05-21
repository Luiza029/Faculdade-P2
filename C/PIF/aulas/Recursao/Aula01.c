#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursao precisa de tres criterios: Precisa ter um ponto de parada, Precisa resolver parte do problema e Ter uma chamada recursiva

void imprimirR(int v[], int i, int f){
    if(i <= f){
        printf("%d ", v[i]);
        imprimirR(v, i+1, f);
    }
}

int main() {
    int vet[3] = {1,2,3};

    imprimirR(vet, 0, 2);
    return 0;
}