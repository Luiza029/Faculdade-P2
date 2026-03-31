#include <stdio.h>

void copia(char *origem, char *destino){

    while(*origem != '\0'){
        *destino = *origem;

        destino++;
        origem++;
    }

    *destino= '\0'; // Quando sair do while, coloco o \0 para n ter lixo de memoria
}

int main(){
    char origem[] = "Programacao";
    char destino[50];

    copia(origem, destino);
    printf("%s", destino);
    return 0;
}