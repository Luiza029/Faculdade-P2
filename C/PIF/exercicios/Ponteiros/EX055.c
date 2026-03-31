/*
    Desafio 3: O Filtro de Pares (Nível Médio-Alto)
Crie uma função chamada copiar_apenas_pares(int *origem, int *destino, int n).

O que fazer: Percorra o vetor de origem. Se o número for par, copie-o para o vetor de destino.

A Pegadinha: No vetor de destino, os números devem ser colocados um após o outro, sem deixar "buracos" (zeros).

Dica de Ponteiros: Você terá um ponteiro que percorre a origem (sempre avança) e um ponteiro de destino que só avança quando você encontra um par.

Retorno: A função deve retornar o endereço de onde o último par foi colocado no destino (ou o endereço inicial se nenhum for encontrado).    
*/

#include <stdio.h>

int Par(int *origem, int *destino, int n){
    int *P_origem = origem; // conteudo de origem
    int *P_destino = destino; // conteudo de destino
    int *fim_origem = origem + n; // endereco do ultimp conteudo
    int i, k = 0;

    while(P_origem < fim_origem){
        if(*P_origem  % 2 == 0){
            *P_destino = *P_origem;
            P_destino++; // so vai mover se ele achar um par (para n criar lixos de memorias)
            k++;
        }
        P_origem++;
    }

    return k;
}

int main(){
    int VetO[10] = {1,2,3,4,5,6,7,8,9,10}, VetD[10] ,n = 10, i;

    int k = Par(VetO, VetD, n); // passo as funçoes como parametro

    for(i=0; i<k; i++){
        printf("%d ", VetD[i]);
    }
    return 0;
}