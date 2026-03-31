#include <stdio.h>

int Sequencia(int n, int m[][3]){
    int i, j, cont = 0, maior = 0, indiceMaior = 0;
    
    for(j=0; j<n; j++){
        cont = 0;
        for(i=0; i<n-1; i++){
            if(m[i+1][j] > m[i][j]){
                cont++;
                if(cont > maior){
                    maior = cont;
                    indiceMaior = j;
                }
            } 
            else{
                cont = 0;
            }
        }
    }
    return indiceMaior;
}

int main(){
    int mat[3][3] = {{1,2,3},{3,4,5},{2,4,5}}, n = 3;
    printf("%d", Sequencia(n, mat));
    return 0;
}