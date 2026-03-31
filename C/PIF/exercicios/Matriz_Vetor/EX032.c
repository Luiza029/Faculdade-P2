#include <stdio.h>

int Remover(int n, int vetE[], int vetS[]);
void imprimir(int r, int vetS[]);

int main(){
    int n = 10, vetE[10] = {5,5,5,2,2,7,3,3,1}, vetS[10];

    int r = Remover(n, vetE, vetS);
    printf("%d\n",r);
    imprimir(r, vetS);
    return 0;
}

int Remover(int n, int vetE[], int vetS[]){
    int i, k = 0, jaExiste, j;

    for(i=0; i<n; i++){
        jaExiste = 0;
        for(j=0; j<k; j++){
            if(vetE[i] == vetS[j]){
                jaExiste = 1;
            }
        }
        if(jaExiste == 0){
            vetS[k] = vetE[i];
            k++;
        }
    }

    return k;
}

void imprimir(int r, int vetS[]){
    for(int i=0; i<r; i++){
        printf("%d ", vetS[i]);
    }
}