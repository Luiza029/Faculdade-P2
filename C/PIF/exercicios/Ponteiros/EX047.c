#include <stdio.h>

int main(){
    int A = 9, B = 1;
    int *PA = &A, *PB = &B;

    int soma = *PA + *PB;

    printf("%d", soma);
    return 0;
}