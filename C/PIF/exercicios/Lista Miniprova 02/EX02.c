#include <stdio.h>

char *cifra_cesar(char *str, int deslocamento){
    char *inicio = str; // vai guardar o endereço inicial da string

    while(*str != '\0'){
        *str = *str + deslocamento;
        str++;
    }

    return inicio;
}

int main() {
    
    char str[50];
    int deslocamento;

    printf("Digite uma palavra: ");
    scanf("%50[^\n]", str);

    printf("Digite o tamanho do deslocamento: ");
    scanf("%d", &deslocamento);

    char *r = cifra_cesar(str, deslocamento);

    printf("%s", r);

    return 0;
}