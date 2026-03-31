#include <stdio.h>

void imprimir(int *vet, int n){
    int i;
    for(i=0; i<n; i++){
        printf("Valor: %d \t|\t Endereco: %p\n", *(vet+i), (vet+i));
    }
}

int main(){
    int vet[10], n = 10, i;

    for(i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    imprimir(vet, n);
    return 0;
}