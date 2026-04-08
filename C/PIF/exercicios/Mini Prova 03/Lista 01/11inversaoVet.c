#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, *vet1, i, *vet2, k=0;

    printf("Digite o tamanho de N: ");
    scanf("%d", &n);

    vet1 = (int*) malloc(n * sizeof(int));
    vet2 = (int*) malloc(n * sizeof(int));

    for(i=0; i<n; i++){
        printf("Preencha o vetore: ");
        scanf("%d", &vet1[i]);
    }

    for(i=n-1; i>=0; i--){
        vet2[k++] = vet1[i];  // ou for(i = 0; i < n; i++){ vet2[i] = vet1[(n-1) - i];}
    }

    for(i=0; i<n; i++){
        printf("%d ", vet2[i]);
    }

    free(vet1);
    free(vet2);
    return 0;
}