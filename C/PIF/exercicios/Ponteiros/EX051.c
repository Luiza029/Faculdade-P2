#include <stdio.h>

void imprimir(int *vet, int n){
    int i;

    for(i=0; i<n; i++){
        printf("Endereco: %p \t|\t Conteudo: %d\n", (vet+i), *(vet+i));
    }
}

int main(){
    int vet[10] = {9,35,2,1,6,68,1,5,9,2}, n = 10;
    int *p = &vet[0];

    imprimir(vet, n); // quando passa uma array, n precisa passar o endereco 
    return 0;
}