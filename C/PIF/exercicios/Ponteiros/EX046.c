#include <stdio.h>

void imprimir(int n, int *vet){
    int i;

    for(i=0; i<n; i++){
        printf("%d = %d\n", i, *(vet+i));
    }
}

int main(){
    int vet[5] = {2,6,4,1,8}, n = 5;

    imprimir(n, vet);
    return 0;
}