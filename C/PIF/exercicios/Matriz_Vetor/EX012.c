#include <stdio.h>

int soma(int n, int arr[n]);

int main(){
    int vet[5] = {1,2,3,4,5};
    int r = soma(5, vet);
    printf("%d", r);
    return 0;
}

int soma(int n, int arr[n]){
    int i = 0, soma = 0;

    for(i=0; i<n; i++){
        soma += arr[i];
    }

    return soma;
}