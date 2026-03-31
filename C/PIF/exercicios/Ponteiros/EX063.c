#include <stdio.h>

int Qtd_Par(int *vet, int n){
    int i, cont = 0;

    for(i=0; i<n; i++){
        if(*(vet+i) % 2 == 0){
            cont++;
        }
    }

    return cont;
}

int main(){
    int vet[10] = {56,3,12,55,7,24,65,32,1,2}, n = 10;

    int r = Qtd_Par(vet, n);
    printf("Qtd de Pares: %d", r);
    return 0;
}