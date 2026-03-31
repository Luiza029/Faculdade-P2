#include <stdio.h>
#include <string.h>

int main(){
    char palavra1[100] = {"Abacate e uva"};
    char palavra2[100];

    printf("Palavra 1: %s\n", palavra1);
    printf("Palavra 2: %s\n", palavra2);
    
    strcpy(palavra2, palavra1); // destino , recurso

    printf("Palavra 1: %s\n", palavra1);
    printf("Palavra 2: %s\n", palavra2);
}