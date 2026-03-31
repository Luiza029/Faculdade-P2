#include <stdio.h>

int strLen(char *str){
    int cont = 0;

    while(*str++){ // Usa o valor atua e dps move o ponteiro 
        cont++;
    } 

    return cont;
}

int main(){
    char str[] = "LUIZA";

    int r = strLen(str);
    printf("%d", r);

    return 0;
}
