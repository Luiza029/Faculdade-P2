#include <stdio.h>
#include <stdlib.h>

void redimensionar(int **vet, int *n){ // usa ** quando eu quero acessar uma variavel que ja é um ponteiro
    *vet = (int*) malloc(*n * sizeof(int));
    int i = 0, v = 1;

    while (1)
    {
        printf("Digite os numeros do vetor: ");
        scanf("%d", &v);

        printf("Vetor: ");
        for(int j=0; j<i; j++){
            printf("%d ", (*vet)[j]);
        }

        printf("\n");
        
        if(v == 0){
            break;
        }

        (*vet)[i] = v;
        i++;

        if(i == *n){
            *n *= 2;
            int *temp = realloc(*vet, *n * sizeof(int));
            
            if(temp == NULL){
                printf("Erro ao alocar memoria");
            }

            *vet = temp;
        }
    }
    
}

int main() {
    int n, *vet;

    printf("Digite o tamanho de N: ");
    scanf("%d", &n);

    redimensionar(vet, &n);
    free(vet);
    vet = NULL;
    return 0;
}