#include <stdio.h>

int multiplos(int n, int vet[], int vetSaida[]);
void imprimir(int r, int vetSaida[]);

int main(){
    int i, vet[10] = {1,2,12,5,6,7,15,9,3,10}, n = 10, vetSaida[10];

    int r = multiplos(n, vet, vetSaida);
    printf("%d\n", r);
    imprimir(r, vetSaida);
    return 0;
}

int multiplos(int n, int vet[], int vetSaida[]){
    int cont = 0, i, k = 0; // k vai percorrer cada interacao linear

    for(i=0; i<n; i++){
        if(vet[i] % 3 == 0){
            vetSaida[k] = vet[i]; // acho qye esta errado por conta do i
            k++;
            cont++;
        }
    }
    return cont;
}

void imprimir(int r, int vetSaida[]){
    for(int i=0; i<r; i++){
        printf("%d ", vetSaida[i]);
    }
}