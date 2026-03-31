#include <stdio.h>

void copiar(char *origem, char *destino){
    
    while(*origem != '\0'){
        *destino = *origem;

        origem++;
        destino++;
    }

    *destino = '\0';
}

int main(){
    char origem[] = "Progrmacao", destino[50];

    copiar(origem, destino);
    printf("%s", destino);
    return 0;
}