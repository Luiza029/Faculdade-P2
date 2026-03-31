#include <stdio.h>

void imprimir(int *vet, int n){
    int i;
    for(i=0; i<n; i++){
        printf("Endereco: %p e Conteudo: %d\n", (vet+i), *(vet+i)); // ou &vet[i] e vet[i], respectivamente
    }
}

int main(){
    int vet[10] = {2,5,62,6,32,1,57,32,1,24}, n = 10;
    int *p = &vet[0];

    imprimir(vet, n);
    return 0;
}