#include <stdio.h>

int Maior(int n, int vet[n]);

int main(){
    int vet[10] = {1, 2, 10, 8, 7, 11, 15, 20, 4, 21}, n = 10;

    int r = Maior(n, vet);
    printf("%d", r);
    return 0;
}

int Maior(int n, int vet[]){
    int i, maior = 0, indiceMaior = 0;

    maior = vet[0];
    for(i=0; i<n; i++){
        if(vet[i] > maior){
            maior = vet[i];
            indiceMaior = i;
        }
    }
    return indiceMaior;
}