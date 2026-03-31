#include <stdio.h>

int main(){
    int x = 10;
    int *p = &x;

    printf("valor inical de X: %d\n", x);
    
    *p = 50;

    printf("Valor de dps de alterar o conteudo de X: %d",*p);
    return 0;
}