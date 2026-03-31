#include <stdio.h>
#include <stdlib.h>

int main() {
    float *VetNotas, soma = 0, media = 0, notas;
    int n, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    VetNotas = (int *) malloc(n * sizeof(float));

    printf("Digite as notas: ");
    for(i=0; i<n; i++){
        scanf("%f", &VetNotas[i]);
    }

    for(i=0; i<n; i++){
        soma += VetNotas[i];
    }

    media = soma / n;

    printf("%:.2f", media);
    free(VetNotas);
    return 0;
}