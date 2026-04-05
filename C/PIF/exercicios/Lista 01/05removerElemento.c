#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int n, *vet, x, i, j, achou = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vet = (int*) malloc(n * sizeof(int));

    for(i=0; i<n; i++){
        printf("Preencha o vetor: ");
        scanf("%d", &vet[i]);
    }

    for(i=0; i<n; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");

    printf("Que numero vc quer excluir: ");
    scanf("%d", &x);

    for(i=0; i<n; i++){
        if(x == vet[i]){
            for(j=i; j<n-1; j++){ // j == i pq quando achar x no vetor, vai pegar o indice e andar com o restante para a esquerda
                vet[j] = vet[j+1];
                achou = 1;
            }
        }
        break;
    }

    if(achou == 0){
        printf("Nao foi possivel achar o elemento");

    } else{
        for(i=0; i<n - 1; i++){
        printf("%d ", vet[i]);
    }
    }

    free(vet);
    vet = NULL;

    return 0;
}