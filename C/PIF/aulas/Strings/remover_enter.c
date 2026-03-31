#include <stdio.h>

// Funciona apenas com fgets, pois ele deixa um espaco no final

int main(){
    char palavra[500];
    int i = 0, tam = 0;

    printf("Digite uma frase: ");
    fgets(palavra, 500, stdin);

    while(palavra[i] != '\n'){
        i++;
    }

    palavra[i] = '\0';
    i = 0;
    
    while(palavra[i] != '\0'){
        tam++;
        i++;
    }

    printf("Tamanho do vetor: %d\n", tam);
    printf("Tamanho de I: %d\n", i);

    return 0;
}