#include <stdio.h>
#include <stdlib.h>

int main() {
    int *mall, *call;
    int n = 5, i;

    mall = (int*) malloc(5 * sizeof(int));
    call = (int*) calloc (5, sizeof(int));

    for(i=0; i<n; i++){
        printf("%d ", *(mall+i));
    }  

    printf("\n");

    for(i=0; i<n; i++){
        printf("%d ",*(call+i));
    }
    
    return 0;
}