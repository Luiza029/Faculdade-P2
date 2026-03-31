#include <stdio.h>

int main() {
    int vet[10], i, menor;

    for (i=0; i<10; i++){
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }   
    
    menor = vet[0];

    for (i=0; i<10; i++){
        if (vet[i] < menor){
            menor = vet[i];
        }
    }

    printf("O menor numero eh: %d", menor);
    return 0;
}