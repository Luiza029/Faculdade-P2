#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arq = fopen("contato.txt", "r");
    char nome[50];

    if(arq){
        while(!feof(arq)){
            if(fgets(nome,50,arq))
                printf("Nome: %s", nome);
        }
        fclose(arq);
    }
    else{
        printf("Nao foi possivel ler o arquivo");
    }
    return 0;
}