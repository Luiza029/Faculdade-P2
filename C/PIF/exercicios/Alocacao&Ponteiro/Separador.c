#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, k = 0, j = 0;
    int *vet, *vetPar, *vetImpar, qtdPar = 0, qtdImpar = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vet = (int*) malloc(n * sizeof(int));

    for(i=0; i<n; i++){
        printf("Digite os numeros dos vetores: ");
        scanf("%d", &*(vet+i));
    }

    for(i=0; i<n; i++){
        k = vet[i];
        j = vet[i];
        
        if(*(vet+k) % 2 == 0){
            qtdPar++;
            k++;
        }

        else if(*(vet+j) % 2 != 0){
            qtdImpar++;
            j++;
        }
    }

    printf("Par: %d\n", qtdImpar);
    printf("Impar: %d\n", qtdPar);

    vetPar = (int*) malloc(qtdPar * sizeof(int));
    vetImpar = (int*) malloc(qtdImpar * sizeof(int));

        

    // limpar
    free(vet);
    free(vetPar);
    free(vetImpar);
    
    vet = NULL;
    vetPar = NULL;
    vetImpar = NULL;
    return 0;
}