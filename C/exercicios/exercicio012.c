#include <stdio.h>

void ehpar (int n, int *resultado){
    if (n % 2 == 0){
        *resultado = 1; 
    } else{
        *resultado = 0;
    }
}

int main(){
    int n, resultado;

    scanf("%d", &n);
    ehpar (n, &resultado);
    printf("Resultado: %d", resultado);
    return 0;
}