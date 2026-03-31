#include <stdio.h>

int main(){
    int x = 21;
    int *p = &x;

    *p += 10;
    
    printf("Novo valor de X eh: %d", x);
    return 0;
}