#include <stdio.h>

int main(){
    int A = 10;
    int *B = &A;
    int **C = &B;
    int ***D = &C;

    printf("Dobro: %d | Triplo: %d | Quabruplo: %d", 2 * *B , 3 * **C, 4 * ***D);
    return 0;
}