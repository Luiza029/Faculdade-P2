#include <stdio.h>
#include <string.h>

int main(){
    char palavra1[100] = {"Abacate"};
    char palavra2[100] = {"Abobora"};
    int resultado;

    resultado = strcmp(palavra1, palavra2);

    printf("Resultado: %d\n", resultado);
    return 0;
}