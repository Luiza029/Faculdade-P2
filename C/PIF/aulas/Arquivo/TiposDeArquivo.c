#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    w -> Escrita (cria o arquivo caso ele nao exista)
    r -> Leitura
    a -> adiciona (adiciona informacoes ao final de um arquivo que JA EXISTE)
    r+ -> Leitura e Escrita
    w+ -> Leitura e Escrita (Apaga o conteudo caso o arquivo exista)
    a+ -> Leitura e Escrita (adiciona ao final do arquivo)
*/

int main() {
    FILE *arquivo = fopen("contato.txt", "w");
    char nome[50] = {"Luiza"};
    int i = 0;

    if(arquivo){
        while(nome[i] != '\0'){
            fputc(nome[i], arquivo);
            i++;
        }
        printf("Escrita finalizada");
        fclose(arquivo);
    }
    else{
        printf("Erro ao tentar criar o arquivo");
    }
    return 0;
}