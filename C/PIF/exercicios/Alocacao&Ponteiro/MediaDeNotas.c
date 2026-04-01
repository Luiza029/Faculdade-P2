#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n;
    float *vetNota, soma = 0, media;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    vetNota = (float*) calloc(n, sizeof(float));
    
    for(i=0; i<n; i++){
        printf("Digite a nota dos alunos: ");
        scanf("%f", &*(vetNota+i));
    }

    for(i=0; i<n; i++){
        soma += *(vetNota+i);
    }

    media = soma / n;
    printf("Media: %.1f\n", media);

    printf("Notas maiores que 7: ");
    for(i=0; i<n; i++){
        if(*(vetNota+i) >= 7){
            printf("%.1f ", *(vetNota+i));
        }
    }

    return 0;
}