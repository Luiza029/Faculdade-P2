#include <stdio.h>

int main(){
    int num = 10;
    int *p = &num;

    printf("Valor inicial de num %d\n", num);

    *p = 80;

    printf("O valor final de num eh: %d", num);
    return 0;
}