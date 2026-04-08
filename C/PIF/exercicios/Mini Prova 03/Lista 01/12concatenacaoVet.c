#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *juncao(int *vet1, int *vet2, int n){
    int *vet3, tam, i, k = 0;
    tam = n*2;

    vet3 = (int*) malloc(tam * sizeof(int));

    for(i=0; i<n; i++){
        vet3[k++] = vet1[i];
    }

    for(i=0; i<n; i++){
        vet3[k++] = vet2[i];
    }

    return vet3;
}

void preecherVetor(int* vet1, int* vet2, int n){
    int i;

    printf("Preencha o vetor 1:\n");
    for(i=0; i<n; i++){
        scanf("%d", &vet1[i]);
    }

    printf("Preencha o vetor 2:\n");
    for(i=0; i<n; i++){
        scanf("%d", &vet2[i]);
    }
}

int main() {
    int n = 5, *vet1, *vet2;

    vet1 = (int*) malloc(n * sizeof(int));
    vet2 = (int*) malloc(n * sizeof(int));

    preecherVetor(vet1,vet2, n);

    int *r = juncao(vet1, vet2, n);

    printf("Vetor 3: ");
    for(int i=0; i<n*2; i++){
        printf("%d ", r[i]);
    }
    return 0;
}