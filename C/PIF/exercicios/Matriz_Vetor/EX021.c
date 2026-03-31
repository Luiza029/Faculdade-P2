#include <stdio.h>

int Contar(int n, int vet[]);

int main(){
    int n = 10, vet[10] = {4,2,9,5,8,3,1,6,7,10};

    int r = Contar(n, vet);
    printf("%d", r);
    return 0;
}

int Contar(int n, int vet[]){
    if(n<2){
        return 0;
    } else{
        int i, num, cont = 0;

        num = vet[n-1];
        for(i=0; i<n-1; i++){
            if(vet[i] < num){
                cont++;
            }
        }

        return cont;
    }
}