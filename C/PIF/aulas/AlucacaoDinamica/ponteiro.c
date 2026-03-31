 /*
    int var, *ptr1, *ptr2;

    var = 10;

    ptr1 = &var;
    ptr2 = &ptr1;
*/

#include <stdio.h>
#include <stdlib.h>

int ** alocaMatriz(int l, int c){
     int **matriz, l = 3, c = 5;
    matriz = (int **) malloc(l * sizeof(int *));

    for(int i=0; i<3; i++){
        matriz[i] = (int *) malloc(c * sizeof(int)); 
    }

    return matriz;
}

void preencherMatriz(int **matriz, int l, int c, int valor){
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            matriz[i][j] = valor;
        }
    }
}

void liberaMatriz(int **matriz, int l){
    for(int i; i<3; i++){
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL;
}

int main() {
    int **m, **n;

    m = alocaMatriz(3,4);
    n = alocaMatriz(4,3);

    // Usando M e N
    preencherMatriz(m, 3, 3, 10);
    preencherMatriz(n, 4, 3, 1);

    // Liberar Memoria
    liberaMatriz(m, 3);
    liberaMatriz(n, 4);
    
    return 0;
}