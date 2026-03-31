void printMatriz(int linha, int coluna, int matriz[10][10]){
    int i, j; 
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

#include <stdio.h>

int main(){
    int i, j, m, n, p, q, k;
    int matA[10][10], matB[10][10], matC[10][10];

    printf("Digite o tamanho da matriz A: ");
    scanf("%d %d", &m, &n);

    printf("Digite o tamnho da matriz B: ");
    scanf("%d %d", &p, &q);

    if (n != p){ // a matriz so pode multiplicar quando a coluna da primeira é igual a linha da segunda
        printf("A matriz tem a linha da matriz A diferente da coluna da matriz B.\n");
        return 1;
    }
    
    printf("Digite os elementos da matriz A:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &matA[i][j]);
        }
    }

    printf("Digite os elementos da matriz B:\n");
    for(i=0; i<p; i++){
        for(j=0; j<q; j++){
            scanf("%d", &matB[i][j]);
        }
    }

    printf("Multiplicar as matrizes\n"); // M x Q (A matriz C vai ser, a linha da primeira e a coluna da segunda)
    for(i=0; i<m; i++){
        for(j=0; j<q; j++){
            matC[i][j] = 0;
            for(k=0; k<n; k++){ // K < n (numeros de colunas da matriz A, que vai ser igual ao numero de colunas da matriz B)
                // o K vai percorrer os elementos da linha i da matriz A e todos os elementos da coluna J da matriz B
                matC[i][j] += matA[i][k] * matB[k][j]; // TEM QUE TER O MAIS IGUAL PARA MULTIPLICAR 
            }
        }
    }

    /*for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ", matA[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(i=0; i<p; i++){
        for(j=0; j<q; j++){
            printf("%d ", matB[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(i=0; i<m; i++){
        for(j=0; j<q; j++){
            printf("%d ", matC[i][j]);
        }
        printf("\n");
    }*/

    printMatriz(m, n, matA);
    printf("\n");
    printMatriz(p, q, matB);
    printf("\n");
    printMatriz(m, q, matC);
    printf("\n");
    
    return 0;
}