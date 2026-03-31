#include <stdio.h>

int procurarElementos(int value, int n, int matriz[n][n]);

int main(){
    int m[3][3] = {{1,2,3},{4,5,6},{7,8,9}}, value = 11;
    int r = procurarElementos(value, 3, m);
    printf("%d", r);
    return 0;
}

int procurarElementos(int value, int n, int matriz[n][n]){
    int flag = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(value == matriz[i][j]){
                flag = 1;
            }
        }
    }

    return flag;
}