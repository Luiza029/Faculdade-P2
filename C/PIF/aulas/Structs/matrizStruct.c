
#include <stdio.h>
#include <string.h>

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
    
    Pessoa pessoa[3][4];
    
    strcpy(pessoa[1][2].nome, "Luiza");
    pessoa[1][2].nascimento.dia = 12;
    pessoa[1][2].nascimento.mes = 13;
    pessoa[1][2].nascimento.ano = 14;

    imprimirPessoa(pessoa[1][2]);
    return 0;
}