#include <stdio.h>

int contarPalavras(char *str){
    
    int cont = 0;
    char anterior = ' '; 

    while(*str != '\0'){
        if(*str != ' ' && anterior == ' '){
            cont++;
        }

        anterior = *str;
        str++; // quando uso o *str, no final do loop eu tenho que andar os enderecos
    }

    return cont;
}

int main(){
    char str[] = {"Ola mundo"};

    int r = contarPalavras(str);
    printf("%d", r);
    return 0;
}