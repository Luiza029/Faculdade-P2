#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removerNegativo(int *vetNum, int n){
    int i, k = 0;

    for(i=0; i<n; i++){
        if(vetNum[i] >= 0){
            vetNum[k++] = vetNum[i];
        } 
    }

    n = k;
    vetNum = realloc(vetNum, n * sizeof(int));

    for(i=0; i<n; i++){
        printf("%d ", vetNum[i]);
    }
}


int main() {
    int n, *vetNum, i;

    printf("Digite o tamanho de N: ");
    scanf("%d", &n);

    vetNum = (int*) malloc(n * sizeof(int));

    for(i=0; i<n; i++){
        printf("Preencha o vetor: ");
        scanf("%d", &vetNum[i]);
    }

    removerNegativo(vetNum, n);

    free(vetNum);
    return 0;
}