#include <stdio.h>

void submatriz(int r,int c,int k,int m[r][c]);



int main(){
    int r,c,k;
    
    scanf("%d %d %d", &r, &c, &k);

    int m[r][c];

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &m[i][j]);
        }
    }

    
    submatriz(r,c,k,m);

    return 0;
}


void submatriz(int r,int c,int k,int m[r][c]){
    int maiorSoma = 0;
    int melhorLinha = 0;
    int melhorColuna = 0;

    for(int i=0; i<=r-k; i++){
        for(int j=0; j<=c-k ;j++){
            int soma=0;

            for (int x = 0; x < k; x++) {//x<2
                for (int y = 0; y < c; y++) {//y<2
                    soma += m[i + x][j + y];
                }
            }

            if(soma>maiorSoma){
                maiorSoma = soma;
                melhorLinha = i;
                melhorColuna = j;
            }
            
        }
    }

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            printf("%d ",m[melhorLinha+i][melhorColuna+j]);
        }
        printf("\n");
    }
}