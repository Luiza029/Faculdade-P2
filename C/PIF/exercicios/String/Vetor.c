#include <stdio.h>

void imprimir(int *vet, int *n){
    int i;

    for(i=0; i<*n; i++){
        printf("%d ", vet[i]);
    }
}

int main(){
    int vet[10] = {1,35,1,35,68,45,31,34,89,12}, n = 10;

    imprimir(vet, &n);
    return 0;
}