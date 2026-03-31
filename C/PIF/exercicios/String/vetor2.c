#include <stdio.h>

void Paridade(int *vetOriginal, int *VetPreenchido, int n){
    int i;

    for(i=0; i<n; i++){
        if(*(vetOriginal+i) % 2 == 0){
            *(VetPreenchido+i) = 0;
        } else{
            *(VetPreenchido+i) = 1;
        }
    }
}

int main(){
    int vetOriginal[5] = {1,2,3,4,5}, vetParidade[5], n = 5, i;

    Paridade(vetOriginal, vetParidade, n);

    for(i=0; i<n; i++){
        printf("%d ", vetOriginal[i]);
    }

    printf("\n");

    for(i=0; i<n; i++){
        printf("%d ", vetParidade[i]);
    }
    return 0;
}