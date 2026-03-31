#include <stdio.h>

int Sub(int n, int *vet, int alvo){
    int i;
    
    for(i=0; i<n; i++){
        if(*(vet+i) == alvo){
            return (vet+i);
        }
    }
    return NULL;
}

int main(){
    int vet[10] = {12,23,1,45,75,8,12,13,47,2}, n = 10, alvo = 2, i;
    int *onde_esta;

    onde_esta = Sub(n, vet, alvo);

    if(onde_esta != NULL){
        *onde_esta = -1;
        printf("Valor encontrado com sucesso\n");
        printf("Endereco do Alvo: %p\n", onde_esta);
        printf("Novo valor: %d\n", *onde_esta);

        for(i=0; i<n; i++){
            printf("%d ", vet[i]);
        }
    } else{
        printf("O valor alvo nao foi encontrado");
    }

    return 0;
}