#include <stdio.h>
#include <stdlib.h>

float calcular(float n1, float n2, float n3){
    float maior;

    maior = (n1 + n2+ abs(n1 - n2)) / 2;

    if (n3 > maior){
        maior = n3;
    }

    return maior;
}

int main(){
    int num1, num2, num3;

    scanf("%d %d %d",&num1, &num2, &num3);

    printf("O maior eh: %.0f", calcular(num1,num2,num3));
    return 0;
}