#include <stdio.h>

int main(){
    int vet[10] = {238,6,2,1,6,8,34,2,35,6,}, n = 10, maior, menor, i;
    int *M = &vet[0], *m = &vet[0];

    maior = vet[0];
    menor = vet[0];
    
    for(i=0; i<n; i++){
        if(vet[i] > maior){
            M = (vet+i); 
            maior = vet[i];
        } if(vet[i] < menor){
            m = (vet+i); 
            menor = vet[i];
        }
    }

    printf("Maior Numero: %d\n", *M);
    printf("Menor Numero: %d", *m);
    return 0;
} 