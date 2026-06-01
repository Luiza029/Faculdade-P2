#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo = fopen("contato.txt", "r");
    char nome[50];
    int i = 0;

    if(arquivo){
        while(!feof(arquivo)){
            char c = fgetc(arquivo);

            if(c == EOF) break;

            nome[i] = c;
            i++;
        }
        nome[i] = '\0';
        fclose(arquivo);
        printf("Arquivo lido com sucesso");
    } 
    else{
        printf("Nao foi possivel ler o arquivo");
    }
    return 0;
}