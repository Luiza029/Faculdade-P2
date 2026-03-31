#include <stdio.h>

int main(){
    int i;
    int notas[5];

    for (i=0; i<5; i++){
        printf("Notas: ");
        scanf("%d", &notas[i]);
            
    }
    for (i=0; i<5; i++){
        printf("%d", notas[i]);
    }

    return 0;
}