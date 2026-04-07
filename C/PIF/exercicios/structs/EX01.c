#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int* valores;
    int tamanho;
}Vetor;

int main() {
    Vetor vet;

    printf("Qual o tamanho do vetor: ");
    scanf("%d", &vet.tamanho);

    vet.valores = (int*) malloc(vet.tamanho * sizeof(int));

    for(int i=0; i<vet.tamanho; i++){
        scanf("%d", &vet.valores[i]);
    }

    for(int i=0; i<vet.tamanho; i++){
        printf("%d ", vet.valores[i]);
    }

    free(vet.valores);
    vet.valores = NULL;
    return 0;
}