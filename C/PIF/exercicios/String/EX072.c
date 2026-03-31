#include <stdio.h>

int palindromo(char *str){
    char *inicio = str;
    char *fim = str;

    while(*fim != '\0'){
        fim++;
    }

    fim--;

    while(inicio < fim){
        if(*inicio != *fim){
            return 0;
        }

        inicio++;
        fim--;
    }

    return 1;
}

int main(){
    char str[] = "ovo";

    int r = palindromo(str);
    printf("%d", r);
    return 0;
}