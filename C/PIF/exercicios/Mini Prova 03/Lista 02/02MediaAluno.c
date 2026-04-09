#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
} Aluno;

float calcularMedia(Aluno a){
    float media;

    media = ((a.nota1 + a.nota2 + a.nota3) / 3);

    return media;
}

int buscarMlhrAluno(Aluno v[], int n){
    int indiceMaior = 0, i;
    float maiorMedia = calcularMedia(v[0]); // diz que a primeira media do vetor é a maior

    for(i=1; i<n; i++){
        float mediaAtual = calcularMedia(v[i]); 

        if(mediaAtual > maiorMedia){
            maiorMedia = mediaAtual;
            indiceMaior = i;
        }
    }

    return indiceMaior;
}

int main() {
    
    int n, i;
    
    printf("Digite a qtd de alunos: ");
    scanf("%d", &n);
    
    Aluno aluno[n];
    
    for(i=0; i<n; i++){
        printf("Digite o nome do %d aluno: ", i+1);
        scanf(" %49[^\n]", aluno[i].nome);
        printf("Digite as tres notas: ");
        scanf("%f %f %f", &aluno[i].nota1, &aluno[i].nota2, &aluno[i].nota3);
    }

    int melhor = buscarMlhrAluno(aluno, n);
    float media = calcularMedia(aluno[melhor]);

    printf("Melhor aluno: %s\n", aluno[melhor].nome);
    printf("Media: %.2f\n", media);
    return 0;
}