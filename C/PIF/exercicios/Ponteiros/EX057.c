#include <stdio.h>

void dobro(int *n){
    int resultado = *n *=2 ;
    printf("Resultado: %d", resultado);
}

int main(){
    int n = 10;

    dobro(&n);
    return 0;
}