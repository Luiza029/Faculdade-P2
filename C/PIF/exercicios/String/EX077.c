#include <stdio.h>

void inverter(char *str){
    char *inicio = str;
    char *fim = str;

    while(*fim != '\0'){
        fim++;
    }

    fim--;

    while(inicio < fim){
        char temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }
}

int main(){
    char str[] = {"Casa Azul"};

    inverter(str);
    printf("%s", str);
    return 0;
}