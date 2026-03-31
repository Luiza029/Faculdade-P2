#include <stdio.h>

void ajustar(int *a, int *b){
    if(*a > *b){
        *a = *a - 1;
        *b = *b + 1;

    } if(*a < *b){
        *a = *a + 1;
        *b = *b - 1;
    } if(*a == *b){
        *a = *a;
        *b = *b;
    }
}

int main(void) {
    int A, B;
    if (scanf("%d %d", &A, &B) != 2) return 0;

    ajustar(&A, &B);

    printf("%d %d\n", A, B);
    return 0;
}