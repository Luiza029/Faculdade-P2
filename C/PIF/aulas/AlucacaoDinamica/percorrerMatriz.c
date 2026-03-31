#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Alocação Dinâmica de uma matriz (precisa de ponteiro para ponteiro)

int main() {
    int **mat, i, j;

    srand(time(NULL));

    mat = malloc(4 * sizeof(int));

    if(mat){
        for(i=0; i<4; i++){
            mat[i] = malloc(3 * sizeof(int));
            if(mat[i] == NULL){
                printf("Erro ao alocar memoria!");
            }
        }

        for(i=0; i<4; i++){
            for(j=0; j<3; j++){
                *(*(mat+i) + j) = 10 + rand() % 90; // mat+i -> vai definir a linha, *(mat+i) -> vai pegar o conteudo do endereço, (*(mat+i) + j) -> Endereco de memoria *(*(mat+i) + j) -> pega o conteudo
                //mat[i][j] = 10 + rand() % 90;
            }
        }

        for(i=0; i<4; i++){
            for(j=0; j<3; j++){
                printf("%d ", *(*(mat+i)+j));
                //printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
    } else{
        printf("Erro ao alocar memoria!\n");
    }

    return 0;
}