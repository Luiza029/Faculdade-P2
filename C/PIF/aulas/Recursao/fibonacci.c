#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int num){
    if(num == 1){
        return 0;
    } 

    else if(num == 2){
        return 1;
    } 

    else{
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

int main() {
    int valor;

    printf("Qual termo vc quer descobrir: ");
    scanf("%d", &valor);

    int r = fibonacci(valor);
    printf("Valor: %d", r);
    return 0;
}