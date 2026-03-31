#include <stdio.h>

int contarLetra(char *str, char letra){
    int cont = 0, i = 0;

    while(*(str+i) != '\0'){
        if(*(str+i) == letra){
            cont++;
        }

        i++;
    }

    return cont;
}

int main(){
    char str[] = {"Banana"}, letra = 'a';

    int r = contarLetra(str, letra);
    printf("%d", r);
    return 0;
}