#include <stdio.h>

void trocaMaior(int *A, int *B){
    int temp;
    if(*B > *A){
        temp = *A;
        *A = *B;
        *B = temp;
    }
} 

int main(){
    int A = 10, B = 90;

    trocaMaior(&A, &B);
    printf("%d %d", A, B);
    return 0;
}