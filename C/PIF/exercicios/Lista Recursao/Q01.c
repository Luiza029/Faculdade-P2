/*
    Implemente recursivamente a função int somaDigitos(int n) que recebe um inteiro não
    negativo e retorna a soma de seus dígitos. Não use laços.
    somaDigitos(123) → 6
    somaDigitos(9) → 9
    somaDigitos(0) → 0
*/

int SomaDigitos(int valor){
    if(valor == 0) return 0;
    
    else{
        return valor % 10 + SomaDigitos(valor /10);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int valor = 123;

    int r = SomaDigitos(valor);
    printf("A soma dos digitos eh: %d", r);
    return 0;
}