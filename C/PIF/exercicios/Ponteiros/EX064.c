#include <stdio.h>

void Ordenar(int *vet, int n){
    int i, j, aux;

    for(i=0; i<n; i++){
        for(j=0; j<n-1-i; j++){
            if(*(vet + j) > *(vet + j + 1)){
                aux = *(vet +j );
                *(vet + j) = *(vet + j + 1);
                *(vet + j + 1) = aux;
            }
        }
    }
}

int main(){
    int vet[5] = {5,3,12,1,2}, n = 5, i;

    Ordenar(vet, n);

    for(i=0 ; i<n; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}