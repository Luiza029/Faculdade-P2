#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x, p, *vetor, i;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vetor = (int*) malloc (n * sizeof(int));

    for(i=0; i<n; i++){
        printf("Digite %d valor: ", i);
        scanf("%d", &vetor[i]);
    }

    for(i=0; i<n; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");

    printf("Qual valor vc quer adicionar no vetor e em qual posicao: ");
    scanf("%d %d", &x, &p);
    
    if(p>=0 && p<=n){

        vetor = (int*) realloc(vetor, (n+1) * sizeof(int));
        for(i=n; i>p; i--){
            vetor[i] = vetor[i - 1];    
        }
        
        vetor[p] = x;
        n++;
        
        for(i=0; i<n; i++){
            printf("%d ", vetor[i]);
        }
    } else{
        printf("Nao existe esse indice");
    }

    free(vetor);
    vetor = NULL;
    return 0;
}