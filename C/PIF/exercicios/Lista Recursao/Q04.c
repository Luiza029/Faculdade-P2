/*
    Implemente recursivamente a função void imprimeInverso(int v[], int inicio, int
    fim) que imprime os elementos do vetor da posição fim até inicio, sem modificar o vetor. Não use
    laços.
*/

void inverter(int vet[], int inicio, int fim){
    if(fim < inicio) return;
    
    else{
        printf("%d ",vet[fim]);
        inverter(vet, inicio, fim-1);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int vet[5] = {4,5,2,1,6}, inicio = 0, fim = 4;

    inverter(vet, inicio, fim);
    return 0;
}