#include <stdio.h>

int moverZeros(int n, int vet[]);
void print(int n, int vet[]);

int main(){
    int vet[10] = {1,0,2,3,0,0,7,4,0,10}, n = 10;

    int r = moverZero(n, vet);
    
    printf("%d\n", r);
    print(n, vet);
    return 0;
}

int moverZero(int n, int vet[]){
    int i, k = 0;

    for(i=0; i<n; i++){
        if(vet[i] != 0){
            vet[k] = vet[i];
            k++;
        }
    }

    for(i=k; i<n; i++){
        vet[i] = 0;
    }

    return k;
}

void print(int n, int vet[]){
    for(int i = 0; i<n; i++){
        printf("%d ", vet[i]);
    }
}