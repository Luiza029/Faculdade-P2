#include <stdio.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[100];
    Data nascimento;
}Pessoa;

Pessoa lerPessoa(){
    Pessoa p;

    printf("Digite o nome da pessoa: ");
    scanf("%100[^\n]", p.nome);
    
    printf("Digite a data de nascimento (dd/mm/aaaa): ");
    scanf("%d %d %d", &p.nascimento.dia, &p.nascimento.mes, &p.nascimento.ano);

    getchar();

    return p;
}

void imprimirPessoa(Pessoa p){
    printf("Nome: %s \t|\t",p.nome);
    printf("Nascimento: %d/%d/%d\n", p.nascimento.dia, p.nascimento.mes, p.nascimento.ano);

}

int main() {
    
    Pessoa pessoa[3]; // armazena 10 pessoas
    int i, n = 3;

    for(i=0; i<n; i++){
        printf("Pessoa %d: \n",i+1);
        pessoa[i] = lerPessoa();
    }

    printf("\n=*=*= Lista de Pessoas =*=*=\n");
    for(i=0; i<n; i++){
        imprimirPessoa(pessoa[i]);
    }

    return 0;
}