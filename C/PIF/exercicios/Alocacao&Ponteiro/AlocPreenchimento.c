#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *vet, soma = 0;

    printf("Digite um valor: ");
    scanf("%d", &n);

    vet = (int*) malloc(n * sizeof(int)); // vai alocar os espacos de memeoria

    for(int i=0; i<n; i++){
        *(vet+i) = i;
    }

    for(int i=0; i<n; i++){
        printf("%d ", *(vet+i));
    }

    for(int i=0; i<n; i++){
        soma += *(vet+i);
    }

    printf("\n");
    printf("Soma = %d ", soma);
    
    free(vet);
    return 0;
}