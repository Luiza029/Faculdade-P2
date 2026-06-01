#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arq = fopen("contato.txt", "w");
    char nome[50] = "Luiza";
    int i=0;

    if(arq){
        for(i=0; i<3; i++){
            printf("Digite um nome: ");
            scanf("%s", nome);
            fputs(nome, arq);
            fputc('\n', arq);
        }

        fclose(arq);
        printf("Escrita finalizada com sucesso");
    }

    else{
        printf("Nao foi possivel abrir o arquivo");
    }
    return 0;
}