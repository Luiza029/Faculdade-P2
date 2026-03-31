#include <stdio.h>

int main(){
    int vet[4] = {4, 7, 3 ,10}, n = 4, i;
    //for(i=0; i<n; i++)
    //scanf("%d", &vet[i]);
    printf("%d Valore maiores que media", Maior(vet,n));
}

int Maior(int vet[], int n){
    int soma = 0, media = 0, cont = 0, i, j;

    for(i=1; i<n; i++){
        soma = 0;
        for(j=1; j<i; j++){
            soma += vet[j];
        }

        media = soma / i;

        if(vet[i] > media){
            cont++;
        }
    }

    return cont;
}