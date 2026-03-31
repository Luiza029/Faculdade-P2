#include <stdio.h>

int main(){
    int matriz[3][3] = {{10,9,8}, {8,6,7}, {5,9,1}}, i, j;

    for(i=0; i<3;i++){
        for(j=0; j<3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}