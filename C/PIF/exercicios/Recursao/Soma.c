#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soma(int valor){
    if(valor == 1){
        return 1;
    }

    else{
        return valor + soma(valor-1);
    }
}

int main() {
    int valor;

    printf("Digite um valor: ");
    scanf("%d", &valor);
    
    int r = soma(valor);
    printf("%d", r);
    return 0;
}