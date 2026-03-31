#include <stdio.h>

int main(){
    int A = 10, B = 90;
    int *PA = &A, *PB = &B;

    // trocar valores de duas variaveis sem uma variavel auxiliar
    *PA = *PA + *PB;
    *PB = *PA - *PB;
    *PA = *PA - *PB;

    printf("Valores trocados: %d %d", A, B);
    return 0;
}