#include <stdio.h>

int trans(int matA[][3], int matB[][3]);

int main(){
    int matA[3][3] = {{1,2,3},{4,5,6},{7,8,9}}, matB[3][3] = {{1,4,7},{2,5,8},{3,6,9}};
    int r = trans(matA, matB);

    printf("%d", r);
    return 0;
}

int trans(int matA[][3], int matB[][3]){
    int n = 3, i, j, ehTrans = 1;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(matA[i][j] != matB[j][i]){
                ehTrans = 0;
            }
        }
    }

    if(ehTrans == 1){
        return 1;
    } else{
        return 0;
    }
}