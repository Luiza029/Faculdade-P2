/*
    x   → valor da variável
    &x  → endereço da variável

    p   → endereço guardado no ponteiro
    *p  → valor no endereço que p aponta
    &p  → endereço do ponteiro
*/

#include <stdio.h>

// Vetor é sempre um ponteiro

void multiplicar(int v[], int tam){ 
    int i;

    for(i=0; i<tam; i++){
        v[i] = v[i] * 2;        
    }
}

void imprimir(int *v, int tam){ // vai funcionar igual a vet[]
    int i;

    printf("%d\n",*v);

    for(i=0; i<tam; i++){
        printf("%d ",v[i]);        
    }
}

int main(){
    int vet[5] = {1,2,3,4,5};

    printf("Antes de Multiplicar");
    imprimir(vet, 5);

    multiplicar(vet,5);
    printf("\nApos Multiplicar\n");
    imprimir(vet, 5);

    return 0;
}
