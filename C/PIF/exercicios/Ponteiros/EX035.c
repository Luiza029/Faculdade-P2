#include <stdio.h>

int main(){
    int a = 10, b = 90;
    int *p = &a;

    // alterar o valor de A
    *p = 45;

    p = &b; // passa a pontar para b e assim conseguindo mudar seu valor

    *p = 12;

    printf("Os valores de A e B sao: %d %d", a, b);

    return 0;
}