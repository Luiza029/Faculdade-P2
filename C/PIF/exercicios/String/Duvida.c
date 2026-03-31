#include <stdio.h>

void MaiorMenor(int *vet, int n, int *maior, int *menor){
    int i;
    
    *maior = *vet;
    *menor = *vet;

    for(i=0; i<n; i++){
        if(vet[i] > *maior){
            *maior = vet[i];
        }

        if(vet[i] < *menor){
            *menor = vet[i];
        }
    }
}

int main(){
    int vet[10] = {238,6,2,1,6,8,34,2,35,6,}, n = 1, maior, menor;

    MaiorMenor(vet, n, &maior, &menor);    
    printf("\tMaior: %d \t Menor: %d", maior, menor);
    return 0;
}