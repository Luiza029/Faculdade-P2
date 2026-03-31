/*
    2. Cópia Invertida
    Crie uma função chamada copiar_reverso(int *origem, int *destino, int n).

    O que fazer: Ela deve copiar os elementos do array de origem para o array de destino, mas na ordem inversa.

    Lógica: Use um ponteiro para percorrer a origem do início ao fim e outro ponteiro para percorrer o destino do fim para o início.

    Regra: Não use variáveis auxiliares de contagem no for. Tente controlar tudo comparando os endereços dos ponteiros.
*/

#include <stdio.h>

void copiar_reverso(int *origem, int *destino, int n){
    int *p_origem = origem;
    int *p_destino = destino + (n-1);
    int *fim_origem = origem + n; 

    while(p_origem < fim_origem){
        *p_destino = *p_origem;
        p_origem++;
        p_destino--;
    }
}

int main(){
    int vet[10] = {1,2,3,4,5,6,7,8,9,10}, n = 10, vet2[10], i;

    copiar_reverso(vet, vet2, n);

    for(i=0; i<n; i++){
        printf("%d ", vet2[i]);
    }

    return 0;
}