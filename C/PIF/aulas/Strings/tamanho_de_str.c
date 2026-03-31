#include <stdio.h>

int main(){
    char palavra[500];
    int i = 0, tam = 0;

    printf("Digite uma frase: ");
    scanf("%500[^\n]", palavra);
    
    while(palavra[i] != '\0'){
        tam++;
        i++;
    }

    printf("Tamanho do vetor: %d\n", tam);
    printf("Tamanho de I: %d\n", i);

    return 0;
}