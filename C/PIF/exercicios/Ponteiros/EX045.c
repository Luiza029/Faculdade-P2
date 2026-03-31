#include <stdio.h>

void Troca(int *n1, int *n2){
    int copia;

    copia = *n1;
    *n1 = *n2;
    *n2 = copia;
}

int main(){
    int n1 = 100, n2 = 1;
    
    printf("N1 = %d | N2 = %d\n", n1,n2);

    Troca(&n1, &n2);
    printf("N1 = %d | N2 = %d", n1,n2);
    return 0;
}