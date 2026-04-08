#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    float *vetNotas;
} Aluno;

int main() {
    int n, i, *qtdNotas, j;
    float mediaAluno = 0, mediaGeral = 0, somaAluno = 0, somaGeral = 0;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    Aluno *alunos = (Aluno*) malloc(n * sizeof(Aluno)); 
    qtdNotas = (int*) malloc(n * sizeof(int));

    for(i=0; i<n; i++){
        printf("Digite o nome do aluno %d: ", i+1);
        scanf(" %49[^\n]", alunos[i].nome);

        printf("Digite a quantidade de notas desse aluno: ");
        scanf("%d", &qtdNotas[i]);

        alunos[i].vetNotas = (float*) malloc(qtdNotas[i] * sizeof(float));

        for(j=0; j<qtdNotas[i]; j++){
            printf("Digite a nota %d: ", j+1);
            scanf("%f", &alunos[i].vetNotas[j]);
        }
    }

    for(i=0; i<n; i++){
        mediaAluno = 0;
        somaAluno = 0;
        for(j=0; j<qtdNotas[i]; j++){
            somaAluno += alunos[i].vetNotas[j];
        }
        mediaAluno = somaAluno / qtdNotas[i]; 
        printf("Nota do %d aluno: %.1f\t", i+1, mediaAluno);
        printf("\n");
        mediaGeral += mediaAluno;
    }
    
    printf("Media geral: %.2f", mediaGeral / n);

    return 0;
}