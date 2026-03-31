#include <stdio.h>
#include <stdlib.h>

// é possivel alocar no MINIMO uma memoria de 8 bits (1 byte)
// Essa memoria recebe um parâmetro, um numero inteiro, indicando a quantidade de bytes que vao ser alocados
// Devolve um ponteiro, ou seja, um endereço de memoria, caso tenha conseguido alocar ou NULL, caso ocorra um problema de alocacao

int main() {
    int *idade;
    
    idade = malloc(sizeof(int)); // vai descobrir quantos bytes de memoria o ponteiro precisa, que vai ser o parametro de malloc

    if(idade){ // qualquer coisa diferente de zero entra no if
        printf("Memoria Alocada com sucesso!\n");
        printf("Idade: %d\n", *idade);
        *idade = 35;
        printf("Idade: %d\n", *idade);
        
    } else{
        printf("Erro ao alocar memoria!\n");
    }

    return 0;
}