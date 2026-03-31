#include <stdio.h>

int diagonal(int n, int mat[][3]);

int main(){
    int mat[3][3] = {{4,7,1},{9,1,2},{1,8,5}}, n = 3;

    int r = diagonal(n, mat);
    printf("%d", r);
    return 0;
}

int diagonal(int n, int mat[][3]){
    int i, j, ehIgual = 1, ValorRef = mat[0][n-1];

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i + j == n - 1 && mat[i][j] != ValorRef){
                ehIgual = 0;
            }
        }
    }

    if(ehIgual == 1){
        return 1;
    } else{
        return 0;
    }
}

