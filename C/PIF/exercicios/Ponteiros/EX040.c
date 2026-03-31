#include <stdio.h>

int main(){
    int A = 100, B = 200, copia;
    int *PA = &A, *PB = &B;
    
    printf("Antes:\tPA = %d e PB = %d\n", *PA, *PB);
    
    copia = *PA;
    *PA = *PB;
    *PB = copia;
    
    printf("Depois\tPA = %d e PB = %d", *PA, *PB);
    return 0;
}