#include <stdio.h>
#include <stdlib.h>

// Como aumentar o tamanho de um vetor com realoc, criando um novo vetor com a nova quantidade de memoria (ela n aumenta o tamanho do vetor)

int main() {
    int *vet, tam, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    
    vet = malloc(tam * sizeof(int)); // declarando o tamanho do vetor

    if(vet){
        for(i=0; i<tam; i++) 
            *(vet+i) = i;

        printf("Tamnho do vetor: %d\n", tam);
        for(i = 0; i<tam; i++) 
            printf("%d ",*(vet+i));

        printf("Digite o novo tamanho do vetor: ");
        scanf("%d", &tam);

        vet = realloc(vet, tam * sizeof(int)); // Na funcao realoc, passa como parametro o vetor e o novo tamnho do vetor vezes o tipo

        if(vet){
            printf("Tamnho do vetor: %d\n", tam);

            for(i=0; i<tam; i++) 
                *(vet+i) = i;

            for(i = 0; i<tam; i++) 
                printf("%d ",*(vet+i));

        } else{
            printf("Erro ao realocar memoria!\n");
        }

    } else{
        printf("Erro ao alocar memoria!\n");
    }

    return 0;
}