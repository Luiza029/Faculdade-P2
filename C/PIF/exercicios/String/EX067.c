#include <stdio.h>

int contarVogais(char *str){
    int cont = 0;

    while(*str != '\0'){ // mais facil para percorrer um vetor
        switch(*str){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                cont++;
                break;
            }
        str++;
    }

    return cont;
}

int main(){
    char str[100];

    printf("Digite uma frase: ");
    scanf("%100[^\n]", str);

    int r = contarVogais(str);
    printf("%d", r);
    return 0;
}