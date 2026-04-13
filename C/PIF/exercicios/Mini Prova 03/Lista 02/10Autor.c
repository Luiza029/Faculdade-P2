#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char titulo[50];
    int ano;
} Livro;

typedef struct{
    char nome[50];
    int qtd_livro;
    Livro livros[10];
}Autor;

Autor autor_com_livro_mais_recente(Autor v[], int n){
    int i, j, maiorAno = v[0].livros[0].ano, indice = 0;

    for(i=0; i<n; i++){
        for(j=0; j<v[i].qtd_livro; j++){
            int atual = v[i].livros[j].ano;

            if(atual > maiorAno){
                maiorAno = atual;
                indice = i;
            }
        }
    }

    return v[indice];
}

int main() {
    int n, i;

    printf("Digite a qtd do autor: ");
    scanf("%d", &n);

    Autor vetA[n];

    for(i=0; i<n; i++){
        printf("Digite o nome do autor: ");
        scanf(" %49[^\n]", vetA[i].nome);

        printf("Digite a quantidade de livros do autor: ");
        scanf("%d", &vetA[i].qtd_livro);

        for(int j=0; j<vetA[i].qtd_livro; j++){
            printf("Digite o titulo do livro: ");
            scanf(" %49[^\n]",vetA[i].livros[j].titulo);

            printf("Digite o ano do livro: ");
            scanf("%d", &vetA[i].livros[j].ano);
        }
    }

    Autor resultado = autor_com_livro_mais_recente(vetA, n);
    printf("Autor com o livro mais recente: %s", resultado.nome);    
    return 0;
}