#include <stdio.h>

int Maior(int *vet, int n){
    int maior = 0, i;

    for(i=0; i<n; i++){
        if(*(vet+i) > maior){
            maior = *(vet+i);
        }
    }

    return maior;
}

int main(){
    int vet[10] = {43,23,46,2,1,46,7,32,55,3}, n = 10;

    int r = Maior(vet, n);
    printf("O maior elemento: %d", r);
    return 0;
}