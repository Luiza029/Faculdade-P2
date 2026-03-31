#include <stdio.h>

int main(){
    int x;
    int *p = &x;

    scanf("%d", &x);

    *p *= 2;

    printf("O dobro eh: %d", x);
    return 0;
}