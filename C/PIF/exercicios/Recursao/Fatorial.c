#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fatorial(int valor){
    if(valor == 1){
        return 1;
    } else{
        return valor * fatorial(valor - 1);
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