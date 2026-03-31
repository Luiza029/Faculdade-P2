#include <stdio.h>

int *MaiorEndereco(int *vet, int n){
    int i, *maior = vet, MaiorEndereco; 

    for(i=0; i<n; i++){
        if(*(vet+i) > *maior){
            maior = vet+i;
        }
    }

    return maior;
}

int main(){
    int vet[5] = {21,53,6,7,2}, n = 5;

    int *r = MaiorEndereco(vet, n);
    printf("Maior valor: %d\n", *r);
    printf("Na Posicao: %ld", r - vet);
    
    return 0;
}