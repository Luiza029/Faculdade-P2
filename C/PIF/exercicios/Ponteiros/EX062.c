#include <stdio.h> 

void inverter(int *vet, int n){
    // pq tenho que declarar como ponteiro?
    int *inicio; 
    int *fim;
    int temp;

    // vai ser para pegar o endereço
    inicio = (vet+0);
    fim = (vet+(n-1));

    while(inicio < fim){
        temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }
}

int main(){
    int vet[5] = {23,67,3,23,8}, n = 5, i;
    
    inverter(vet, n);
    for(i=0; i<n; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}