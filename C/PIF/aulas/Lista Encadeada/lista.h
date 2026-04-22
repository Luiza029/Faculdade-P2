#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct no {
    int valor; // o valor que o nó guarda
    struct no *proximo; // ponteiro para o proximo nó
} No;

typedef struct {
    No *inicio; // aponta para o primeiro nó
    int tam; // quantos nó existem
}Lista;

Lista* criarLista();
void inserirInicio(Lista *lista, int valor);
void inserirFim(Lista *lista, int valor);
void inserirOrdenado(Lista *lista, int valor);
No* pesquisar(No *inicio, int val);
No* remover(Lista *lista, int val);
void imprimir(No *inicio);

#endif // FILA_H_INCLUDED
