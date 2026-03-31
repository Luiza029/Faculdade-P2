#include <stdio.h>

int comprimento(char *str){

    int cont = 0;

    while(*str != '\0'){
        cont++;
        str++;
    }

    return cont;
}

int main() {
    
    char str[100];

    printf("Digite uma palavra: ");
    scanf("%100[^\n]", str);

    int r = comprimento(str);

    printf("Comprimento da string: %d", r);
    return 0;
}