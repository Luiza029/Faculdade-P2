#include <stdio.h>

void troca(int *n1, int *n2){
    int copia;
    copia = *n1;
    *n1 = *n2;
    *n2 = copia;
}

int main(){
    int n1 = 12, n2= 00;

    troca(&n1, &n2);
    printf("N1: %d | N2: %d", n1, n2);

    return 0;
}