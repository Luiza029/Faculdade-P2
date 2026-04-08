#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remover(int *vet, int n){
    int i, k = 0;

    for(i=0; i<n; i++){
        if(vet[i] >= 0){
            vet[k++] = vet[i];
        }
    }

    vet = realloc(vet, k * sizeof(int));
    n = k;

    for(i=0; i<n; i++){
        printf("%d ", vet[i]);
    }
}

int main() {
    int n, *vet, i;
    
    printf("Digite o tamanho de N: ");
    scanf("%d", &n);

    vet = (int*) malloc(n * sizeof(int));

    for(i= 0; i<n; i++){
        printf("Digite o valor: ");
        scanf("%d", &vet[i]);
    }

    remover(vet, n);
    free(vet);

    return 0;
}