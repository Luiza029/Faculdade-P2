/*
    Implemente recursivamente a função int maiorElemento(int m[][MAX], int lin, int
    col, int n) que percorre uma matriz quadrada n x n e retorna o maior elemento. A travessia
    deve avançar coluna por coluna e, ao chegar na última coluna, passar para a próxima linha.
    Nenhum laço é permitido.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maiorElemento(int m[][3], int lin, int col, int n){
    if(lin == n) return 0;
    if(col == n) return maiorElemento(m, lin + 1, 0, n);
    
    int maior = maiorElemento(m, lin, col + 1, n);

    if(m[lin][col] > maior) return m[lin][col];
    else return maior;
}

int main() {
    
    return 0;
}