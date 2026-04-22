#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criarLista(){
    Lista *lista = malloc(sizeof(Lista)); // aloca memoria 
    if(lista){
        lista->inicio = NULL; // comeca sem proximo
        lista->tam = 0;
    }
	else
		printf("\n\tErro ao alocar memoria...");
    return lista;
}

void inserirInicio(Lista *lista, int valor) {
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = valor;
        novo->proximo = lista->inicio; // novo nó aponta para quem era o inicio
        lista->inicio = novo; // o inicio é o novo nó
        lista->tam++;
    }
    else{
        printf("\n\tErro ao alocar memoria...\n");
    }
}

void inserirFim(Lista *lista, int valor) {
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = valor;
        novo->proximo = NULL; // vai para o final

        // lista vazia
        if(lista->inicio == NULL)
            lista->inicio = novo;

        else{ // vai com a variavel aux ate o último nó
            No *aux = lista->inicio;

            while(aux->proximo) // para quando o proximo for igual a null
                aux = aux->proximo; // avanca

            aux->proximo = novo; // aux agr é o ultimo, conecta o novo
        }
        lista->tam++;
    }
    else{
        printf("\n\tErro ao alocar memoria...\n");
    }
}

void inserirOrdenado(Lista *lista, int valor) {
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = valor;

        // lista vazia ou se o numero digitado for menor que o do inicio 
        if(lista->inicio == NULL || lista->inicio->valor > novo->valor){
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else{
            No *aux = lista->inicio;

            // para quando o proximo for maior que novo
            while(aux->proximo && aux->proximo->valor < novo->valor) // O while usa aux->proximo->valor (não aux->valor) porque precisamos parar 1 nó ANTES do lugar de inserção
                aux = aux->proximo;

            // encaixa o novo entre aux e aux -> proximo
            novo->proximo = aux->proximo; // novo aponta para a frente
            aux->proximo = novo; // aux aponta para o novo
        }
        lista->tam++;
    }
    else{
        printf("\n\tErro ao alocar memoria...\n");
    }
}

No* pesquisar(No *inicio, int val) {
    while (inicio && inicio->valor != val)
        inicio = inicio->proximo;
    return inicio;
}

No* remover(Lista *lista, int val) {
    No *anterior, *remover = NULL;
    if(lista->inicio){

        // remover o inicio 
        if(lista->inicio->valor == val){
            remover = lista->inicio;
            lista->inicio = remover->proximo; // avanca o inicio
            lista->tam--;
        }
        
        // anda ate o nó anterior ao que vai sair
        else{
            anterior = lista->inicio;
            while (anterior->proximo && anterior->proximo->valor != val)
                anterior = anterior->proximo;
            if (anterior->proximo) {
                remover = anterior->proximo;
                anterior->proximo = remover->proximo; // pula o nó removido: anterior aponta pro nó dps dele
                lista->tam--;
            }
        }
    }
    return remover;
}

void imprimir(No *inicio){
    while(inicio){ // enquanto inicio for diferente de nulo, o while vai ficar rodando
        printf("%d ", inicio -> valor);
        inicio = inicio -> proximo;
    }

    printf("\n");
}

int main(){
    Lista *lista = criarLista();
    int opcao, valor;
    No *no;

    do{
        
        printf("[0] Sair\n");
        printf("[1] Inserir no inicio\n");
        printf("[2] Inserir no fim\n");
        printf("[3] Inserir Ordenado\n");
        printf("[4] Remover\n");
        printf("[5] Imprimir\n");
        printf("[6] Pesquisa\n");
        
        scanf("%d", &opcao);
        
        switch(opcao){
            case 0:
            printf("Saindo");
            
            break;
            
            case 1:
            printf("Digite o valor a ser inserido no inicio: ");
            scanf("%d", &valor);
            inserirInicio(lista, valor);
            
            break;
            
            case 2:
            printf("Digite um valor para ser inserido no fim: ");
            scanf("%d", &valor);
            inserirFim(lista, valor);
            
            break;
            
            case 3:
            printf("Digite o valor a ser inserido ordenado: ");
            scanf("%d", &valor);
            inserirOrdenado(lista, valor);
            
            break;
            
            case 4:
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            
            no = remover(lista, valor);
            
            if(no){
                printf("Removido: %d\n", no -> valor);
                free(no);
                
            } else{
                printf("Valor nao encontrado\n");
            }
            
            break;
            
            case 5:
            printf("Lista: %d\n", lista -> tam);
            imprimir(lista -> inicio);
            
            break;
            
            case 6:
            printf("Digite o valor a ser pesquisado: ");
            scanf("%d", &valor);
            no = pesquisar(lista -> inicio, valor);
            
            if(no){
                printf("Valor encontrado!\n");
            }
            
            break;
            
            default:
            printf("Opcao invalida\n");
        }
            
    } while(opcao != 0);
  
        
        return 0;
}
