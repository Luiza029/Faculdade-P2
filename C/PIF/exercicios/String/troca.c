#include <stdio.h>

void troca(int *a, int *b){
    int troca;
    troca = *a;
    *a = *b;
    *b = troca;
}

int main(){
    int A = 1, B = 3;

    troca(&A, &B);
    printf("A = %d | B = %d", A, B);
    return 0;
}