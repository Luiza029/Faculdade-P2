#include <stdio.h>

int Simetrica(int n, int mat[][3]);

int main(){
    int n = 3, mat[3][3] = {{2,1,3},{1,4,5},{3,5,6}};

    int r = Simetrica(n, mat);
    printf("%d", r);
    return 0;
}

int Simetrica(int n, int mat[][3]){
    int i, j, ehSimetrica = 1;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(mat[i][j] != mat[j][i]){
                ehSimetrica = 0;
            }
        }
    }

    if(ehSimetrica == 1){
        return 1;
    } else{
        return 0;
    }
}
