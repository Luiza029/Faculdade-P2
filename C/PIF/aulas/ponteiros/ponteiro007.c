// ponteiro para ponteiro
#include <stdio.h>

int main(){
    int A = 50, *B, **C; // C é ponteiro de ponteiro

    B = &A;
    C = &B; // Por C ser um ponteiro de ponteiro, ela so aceita endereco de ponteiro

    printf("Endereco de A: %p \tConteudo de A: %d\n", &A, A);
    printf("Endereco de B: %p \tConteudo de B: %p \t Conteudo apontado por B: %d\n", &B, B, *B);
    printf("Endereco de C: %p \tConteudo de C: %p \t Conteudo apontado por C: %d\n", &C, C, **C);
    return 0;
}