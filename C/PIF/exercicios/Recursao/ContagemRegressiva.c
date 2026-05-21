#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void regressiva(int valor){ // 10 9 8
    if(valor < 0){
        return;
    } else{
        printf("%d ", valor);
        regressiva(valor-1);
    }
}

int main() {
    int valor;

    printf("Digite um valor para fazer uma contagem regressiva: ");
    scanf("%d", &valor);

    regressiva(valor);
    return 0;
}