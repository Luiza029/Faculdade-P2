#include <stdio.h>

int Crescente(int n, int mat[][3]);

int main(){
    int n = 3, mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    int r = Crescente(n, mat);
    printf("%d", r);
    return 0;
}

int Crescente(int n, int mat[][3]){
    int i, j, ehCres = 1;

    for(i=0; i<n; i++){
        for(j=0; j<n-1; j++){
            if(mat[i][j] > mat[i][j+1]){
                ehCres = 0;
            }
        }
    }

    if(ehCres == 1){
        return 1;
    } else{
        return 0;
    }
}