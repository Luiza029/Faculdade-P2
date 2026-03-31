#include <stdio.h>

void inverter(char *str){
    char *inicio = str; // vai pegar o primeiro valor do vetor
    char *fim = str; // vai pegar o primieiro valor, logo tenho que passar para o ultimo;

    while(*fim != '\0'){
        fim++;
    }

    fim--; // por conta do \0 tem que voltar uma casa, ou seja, para a memoria que tem um caracter

    while(inicio < fim){
        char temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}

int main(){
    char str[] = "Programacao";

    inverter(str);
    printf("%s", str);
    return 0;
}