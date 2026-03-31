#include <stdio.h>

char *buscaChar(char *str, char achar){
    
    while(*str != achar && *str != '\0'){
        str++;
    }

    if(*str != '\0'){
        return str;
    } else{
        return NULL;
    }
}

int main(){
    char str[] = "Programacao eh muito chato";
    char *p = buscaChar(str, 'c');

    printf("%s", p);
    return 0;
}