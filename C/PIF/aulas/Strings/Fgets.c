#include <stdio.h>

int main(){
    char palavras[100];

    printf("Digite seu nome: ");
    fgets(palavras, 100, stdin); // o nome do ventro, tamanho do vetor e entrada padrão

    printf("%s", palavras);
    return 0;
}