#include <stdio.h>

int main(){
    int A, B = 1;

    if(&A > &B){
        printf("A tem o maior endereco");
    } else if(&B > &A){
        printf("B tem o maior endereco");
    } else{
        printf("Ambas tem o msm endereco");
    }

    return 0;
}