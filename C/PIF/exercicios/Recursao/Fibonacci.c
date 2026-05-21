#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int valor){
    if(valor == 0){
        return 0;
    }

    else if(valor == 1){
        return 1;
    }

    else{
        return fibonacci(valor - 1) + fibonacci(valor - 2);
    }
}

int main() {
    int valor;
    
    printf("Digite um valor: ");
    scanf("%d", &valor);

    int r = fibonacci(valor);
    printf("%d", r);
    return 0;
}