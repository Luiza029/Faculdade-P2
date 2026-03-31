// Aritmetrica de ponteiro com vetor
#include <stdio.h>

void imprimir(int *v, int n){
    int i;

    for(i=0; i<n; i++){
        printf("%d = %d\n", i, *(v+i));
    }
}

int main(){
    int vet[9] = {10,20,30,40,50,60,70,80,90};

    //printf("0 = %d\n", *vet); // pega o primeiro conteudo do vetor
    //printf("1 = %d\n", *(vet+1)); // pega o segundo conteudo do vetor
    //printf("2 = %d\n", *(vet+2)); // pega o terceiro conteudo do vetor

    imprimir(vet, 9);
    return 0;
}