#include <stdio.h>

int main(){
    int mat[3][3] = {{-1,2,3},{-4,-5,-6,},{7,8,-9}}, n = 3;
    printf("Tiveram %d mudancas de sinais", Mudanca(n, mat));
    return 0;
}

int Mudanca(int n, int mat[][3]){
    int i, j, cont = 0, vetLinha[9], k = 0;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            vetLinha[k] = mat[i][j];
            k++;
        }
    }

    for(i=0; i<k; i++){
        if((vetLinha[i] > 0 && vetLinha[i+1] < 0) || (vetLinha[i] < 0 && vetLinha[i+1] > 0)){
            cont++;
        }
    }
    return cont;
}