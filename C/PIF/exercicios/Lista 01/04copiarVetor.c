#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int n, *vet1, *vet2, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vet1 = (int*) calloc(n, sizeof(int));
    vet2 = (int*) calloc(n, sizeof(int));
    
    for(i=0; i<n; i++){
        printf("Preencha os valores do vetor: ");
        scanf("%d", &vet1[i]);
    }

    for(i=0; i<n; i++){
        vet2[i] = vet1[i]; 
    }

    printf("Vetor 2 = ");
    for(i=0; i<n; i++){
        printf("%d ", vet2[i]);
    }

    free(vet1);
    free(vet2);

    vet1 = NULL;
    vet2 = NULL;

    return 0;
}