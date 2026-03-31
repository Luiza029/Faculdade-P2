#include <stdio.h>

int main(){
    int idade = 20;
    char sexo = 'f';

    // Como criar um ponteiro
    int *pi = &idade; // * indica que a variavel é um ponteiro, que vai guardar um endereco de memoria
    char *ps = &sexo;

    printf("Enderoco de idade: %p \t Idade: %d\n", &idade, idade); // O & no print, fornece o print do endereco da variavel
    printf("Endereco de Sexo: %p \t Sexo: %c", &sexo, sexo);

    printf("\n");
    
    printf("\nEndereco de PI: %p\t Conteudo de PI: %p \t Conteudo apontado por PI: %d\n", &pi, pi, *pi); // Endereco de PI, Enderoço do conteudo de PI e conteudo do de PI
    printf("\nEndereco de PS: %p\t Conteudo de PS: %p \t Conteudo apontado por PS: %c\n", &ps, ps, *ps); // Endereco de PS, Enderoço do conteudo de PS e conteudo do de PS

    return 0;
}