#include <stdio.h>

void soma(int x, int y, int *r){
    *r = x + y;
}

int main(){
    int x = 10, y = 20, resultado;

    soma(x, y, &resultado);
    printf("Soma = %d", resultado);

    return 0;
}