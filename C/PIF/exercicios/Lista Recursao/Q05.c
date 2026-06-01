/*
    Dada uma matriz quadrada n x n, implemente recursivamente a função int somaLinha(int
    m[][MAX], int linha, int col, int n) que retorna a soma de todos os elementos de
    uma linha específica. Use-a para imprimir a soma de cada linha da matriz. Não use laços internos
    à função.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int somaLinha(int matriz[3][3], int linha, int col, int n){
    if(col < 0) return 0;
    else return matriz[linha][col] + somaLinha(matriz, linha, col - 1, n);
}

void imprimirSoma(int matriz[3][3], int linha, int n){
    if(linha < 0) return;
    else{
        printf("%d ", somaLinha(matriz, linha, n-1, n));
        imprimirSoma(matriz, linha - 1, n);
    }
}

int main() {
    int matriz[3][3] = {{1,4,6}, {5,7,2}, {1,8,9}}, linha = 2, col = 2, n = 3;

    imprimirSoma(matriz, n-1, n);
    return 0;
}