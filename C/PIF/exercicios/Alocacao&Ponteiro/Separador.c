#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *vet, *vetPar, *vetImpar, qtdPar = 0, qtdImpar = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vet = (int*) malloc(n * sizeof(int));

    for(i=0; i<n; i++){
        printf("Digite os numeros dos vetores: ");
        scanf("%d", &vet[i]);
    }

    for(i=0; i<n; i++){
        if(*(vet+i) % 2 == 0){
            qtdPar++;
        }

        else if(*(vet+i) % 2 != 0){
            qtdImpar++;
        }
    }

    printf("Par: %d\n", qtdPar);
    printf("Impar: %d\n", qtdImpar);

    vetPar = (int*) malloc(qtdPar * sizeof(int));
    vetImpar = (int*) malloc(qtdImpar * sizeof(int));

    for(i=0; i<qtdPar; i++){
        if(vet[i] % 2 == 0){
            vetPar[i] = vet[i];
        }
    }

    for(i=0; i<qtdImpar; i++){
        if(vet[i] % 2 != 0){
            vetImpar[i] = vet[i];
        }
    }

    for(i=0; i<qtdPar; i++){
        printf("%d ", vetPar[i]);
    }

    printf("\n");

    for(i=0; i<qtdImpar; i++){
        printf("%d ", vetImpar[i]);
    }

    // limpar
    free(vet);
    free(vetPar);
    free(vetImpar);
    
    vet = NULL;
    vetPar = NULL;
    vetImpar = NULL;
    return 0;
}