#include <stdio.h>

void contador(char *str, int *contN, int *contL, int *contE){
    while(*str != '\0'){

        if(*str >='0' && *str <= '9'){ // numeros sao considerados caracteres aq!!!
            (*contN)++;
        } else if((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')){ // para pegar tanto maiuscula e menusculas
            (*contL)++;
        } else if(*str != ' '){ // para n contar espacos
            (*contE)++;
        }

        str++;
    }
}

int main() {
    char str[] = "AMANGA CHATA 012!!";
    int contNumeros = 0, contLetras = 0, contEspeciais = 0;

    contador(str, &contNumeros, &contLetras, &contEspeciais);

    printf("Qtd de Numeros: %d\n", contNumeros);
    printf("Qtd de letras: %d\n", contLetras);
    printf("Qtd de Caracteres especiais: %d\n", contEspeciais);

    return 0;
}