#include <stdio.h>

int main(){
    char palavras[3];
    int x = 0;

    printf("Digite uma frase: ");
    scanf("%3[^\n]", palavras);  // nao precisa de & para ler string (APENAS PARA STRINGS !!!!!!) | Vai ler exatamente 10
    // [^\n] vai ler ate que ocorra um contra barra N

    printf("%s", palavras);
    printf("%d", x);

    return 0;
}