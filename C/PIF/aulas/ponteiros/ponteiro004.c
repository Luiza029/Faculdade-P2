#include <stdio.h>

void imprimir(int *val){
    printf("Idade: %d\n", *val);
    *val = 11; // alterou o conteudo apontado pelo endereco de memoria
    printf("Idade 2: %d\n", *val);
}

int main(){
    int idade = 29;

    imprimir(&idade); // vai receber o endereco da variavel idade
    printf("Idade na main: %d", idade);
    return 0;
}