#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    float notas[4];
} Aluno;

float media_turma(Aluno v[], int n){
    int i; 
    float soma = 0, media = 0;

    for(i=0; i<n; i++){
        for(int j=0; j<4; j++)
            soma += v[i].notas[j];
    }

    media = soma / (n * 4);

    return media;
}

int main() {
    int n, i;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    Aluno vetN[n];

    for(i=0; i<n; i++){
        printf("Aluno %d:\n", i+1);
        printf("Digite o nome do aluno: ");
        scanf(" %49[^\n]", vetN[i].nome);

        printf("Digite as 4 notas do aluno: \n");
        for(int j=0; j<4; j++){
            scanf("%f", &vetN[i].notas[j]);
        }
    }

    float r = media_turma(vetN, n);

    printf("Media: %.2f", r);
    return 0;
}