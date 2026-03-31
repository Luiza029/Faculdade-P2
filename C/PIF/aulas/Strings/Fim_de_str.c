#include <stdio.h>

int main(){
    char palavras[500];
    int i = 0;

    printf("Digite uma frase: ");
    scanf("%500[^\n]", palavras);

    printf("%s\n", palavras);

    while(palavras[i] != '\0'){ // o while é o mais ideal, pois o for iria percorrer o vetor do inicio ao fim
        printf("\t%d = %c\n", i, palavras[i]);
        i++;
    }

    return 0;
}