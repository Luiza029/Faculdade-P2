#include <stdio.h>

int strLen(char *str){
    int cont = 0;

    while(*str != '\0'){
        cont++;
        str++;
    }

    return cont;
}

int main(){
    char str[] = {"Amanga Chata"};

    int r = strLen(str);
    printf("%d", r);
    return 0;
}