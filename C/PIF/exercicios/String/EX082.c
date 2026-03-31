#include <stdio.h>

void contador(char *str){

    char *inicio = str;
    char *fim = str;

    while(*fim != '\0'){
        fim++;
    }

    fim--;

    while(inicio < fim-1){
        if(*inicio == *(inicio + 1)){
            *inicio = '*';
            *(inicio + 1) = '*';
        }
        inicio++;
    }
}

int main() {
    char str[] = {"massa de boooolo"};

    contador(str);
    printf("%s\n", str);
    return 0;
}