#include <stdio.h>

int main(){
    int vet[10], n = 10, i;
    int *p = &vet[0]; 

    for(i=0; i<n; i++){
        printf("%d\n",*(p+i) = i * 2);
    }

    return 0;
}