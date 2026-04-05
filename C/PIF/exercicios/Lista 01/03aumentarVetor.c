#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5, m = 10, *vetor, i;
    
    vetor = (int*) malloc(n * sizeof(int));

    printf("Digite o numeros do vetor: \n");
    for(i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }

    for(i=0; i<n; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");

    vetor = realloc(vetor, m * sizeof(int));

    printf("Digite os novos numeros do vetor: \n");
    for(i=n; i<m; i++){ // O for de preencher os novos valores, tem que comecar apartir do ultimo indice do vetor antes do realloc (se for recomecar tudo, usa i=0)
        scanf("%d", &vetor[i]);
    }


    for(i=0; i<m; i++){
        printf("%d ", vetor[i]);
    }

    free(vetor);
    vetor = NULL;

    return 0;
}