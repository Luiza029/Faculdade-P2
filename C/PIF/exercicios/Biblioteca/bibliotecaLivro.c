#include <stdio.h>
#include "livros.h"

#define VEC_SIZE 10

int main() {
    
    Livro vet_livros[VEC_SIZE];
    Livro l;

    for(int i=0; i<VEC_SIZE; i++){
        inserirLivro(l, vet_livros);
    }
    
    return 0;
}