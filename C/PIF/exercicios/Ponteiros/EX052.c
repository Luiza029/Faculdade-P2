#include <stdio.h>

void imprimir(int n, int *vet){
    int i;

    for(i=0; i<n; i++){
        printf("%p \n", (vet+i));
    }
}

int Maior(int n, int *vet){
    int i, maior = vet[0];
    int *enderecoMaior = vet;

    for(i=0; i<n; i++){
        if(vet[i] > maior){
            maior = vet[i];
            enderecoMaior = (vet+i);
        }
    }

    return enderecoMaior;
}

int main(){
    int vet[10] = {2,52,46,2,1,4,7,2,1,32,4}, n = 10;

    imprimir(n, vet);
    printf("\n\n");

    int *maior = Maior(n, vet);
    printf("%p",maior);
    return 0;
}