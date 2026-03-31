#include <stdio.h>

int qtdPares(int n, int vetor[n]);

int main(){
    int vet[5] = {1,2,3,4,5}, n = 5;
    int r = qtdPares(n, vet);

    printf("%d", r);
    return 0;
}

int qtdPares(int n, int vetor[n]){
    if(n == 0){
        return 0;
    } else{
        int cont = 0;

        for(int i = 0; i<n; i++){
            if(vetor[i] % 2 == 0){
                cont ++;
            }
        }

        return cont;
    }
}

