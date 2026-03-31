#include <stdio.h>

int main(){
    float n = 3.14159;
    float a, r;

    scanf("%f", &r);

    a = n * (r*r);

    printf("A = %.4f", a);

    return 0;
}  