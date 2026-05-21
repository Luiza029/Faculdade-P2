#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int potencia(int x, int y){
    if(y == 0){
        return 1;
    } else{
        return x * potencia(x, y - 1);
    }
}

int main() {
    int x, y;

    printf("Digite um valor para X e outro para Y: ");
    scanf("%d %d", &x, &y);

    int r = potencia(x, y);
    printf("%d", r);
    return 0;
}