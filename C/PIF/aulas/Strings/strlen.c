#include <stdio.h>
#include <string.h>

int main(){
    char palavras[500];
    int tam;

    printf("Digite uma frase: ");
    scanf("%500[^\n]", palavras);

    tam = strlen(palavras);

    printf("Tamanho: %d\n", tam);
}