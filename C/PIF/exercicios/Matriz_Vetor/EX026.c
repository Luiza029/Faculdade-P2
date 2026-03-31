#include <stdio.h>

int Maior(int n, int vet[]);

int main(){
    int vet[6] = {8,5,5,7,2,1}, n = 6;

    int r = Maior(n, vet);
    printf("%d", r);
    return 0;
}

int Maior(int n, int vet[]){
    int i, cont = 0;

    for(i=0; i<n-1; i++){
        if(vet[i] > vet[i+1]){
            cont++;
        }
    }

    return cont;
}