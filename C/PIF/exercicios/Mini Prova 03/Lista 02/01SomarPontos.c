#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int x;
    int y;
} Ponto;

Ponto SomaPontos(Ponto a, Ponto b){
    Ponto resultado;

    resultado.x = a.x + b.x;
    resultado.y = a.y + b.y;

    return resultado;
}

int main() {

    Ponto a, b;

    printf("Digite os valores de X1 e Y1: ");
    scanf("%d %d", &a.x, &a.y);

    printf("Digite os valores de X2 e Y2: ");
    scanf("%d %d", &b.x, &b.y);

    Ponto resultado = SomaPontos(a,b);

    printf("%d %d", resultado.x, resultado.y);
    return 0;
}