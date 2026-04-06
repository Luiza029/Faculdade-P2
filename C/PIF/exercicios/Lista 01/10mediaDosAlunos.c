#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int qtd, i;
    float media = 0, soma = 0, *vetNotas;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &qtd);

    vetNotas = (float*) malloc(qtd * sizeof(float));

    for(i=0 ;i<qtd; i++){
        printf("Digite a nota do %d aluno: ", i+1);
        scanf("%f", &vetNotas[i]);
    }
    
    for(i=0; i<qtd; i++){
        soma += vetNotas[i];
    }
    
    media = soma / qtd;

    printf("%.1f", media);
    free(vetNotas);
    vetNotas = NULL;

    return 0;
}