#include <stdio.h>
#include <stdlib.h>

// Alocação Dinâmica de vetor

int* alocarM(int qtd){
    int *x = malloc(qtd * sizeof(int));
    return x;
}

void imprimir(int *vet, int tam){
    int i;

    for(i=0; i<tam; i++){
            printf("%d ", *(vet+i));
        }
}

void preencher(int *vet, int tam){
    int i;

    for(i=0; i<tam; i++) *(vet+i) = i;
}

int main() {
    int *vet, tam = 50; // se, [], pois ele faria uma alocação estatica e sem [] é uma alocação dinamica

    // vet = malloc(10 * sizeof(int)); // quero alocar 10 espaços no vetor, e cada espaço de um inteiro ocupa 4 bytes, logo 10 * 4 = 40
    vet = alocarM(tam);

    if(vet){
        preencher(vet, tam);
        imprimir(vet, tam);
    } else{
        printf("Erro ao alocar memoria!\n");
    }

    return 0;
}