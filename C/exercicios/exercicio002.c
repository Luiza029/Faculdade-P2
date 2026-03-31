#include <stdio.h>

int main(){
    double raio, area, pi = 3.14159;

    scanf("%lf", &raio);

    area = pi * raio * raio;

    printf("X = %.4lf", area);

    return 0;
}