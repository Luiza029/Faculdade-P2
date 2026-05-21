#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fatorial(int num){
    if(num == 1){ // caso o valor seja 1
        return 1;
    }

    else{
        return num * fatorial(num-1);
    }
}

int main() {
    int valor;

    printf("Digite um valor maior que zero: ");
    scanf("%d", &valor);

    int r = fatorial(valor);
    printf("Resultado: %d", r);
    return 0;
}