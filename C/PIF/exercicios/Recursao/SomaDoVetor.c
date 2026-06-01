#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soma(int vet[], int i){
    if(i == 0){
        return 0;
    } else{
        return vet[i-1] + soma(vet, i-1);
    }
}

int main() {
    int vet[5];
    
    for(int i=0; i<5; i++){
        printf("Digite os valores do vetor: ");
        scanf("%d", &vet[i]);
    }

    int r = soma(vet, 5);
    printf("A soma eh: %d", r);
    return 0;
}