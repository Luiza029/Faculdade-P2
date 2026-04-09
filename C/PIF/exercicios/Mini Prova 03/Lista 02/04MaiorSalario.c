#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    float salario_base;
    float bonus;
} Funcionario;

int buscar_maior_total(Funcionario v[], int n){
    int indice = 0, i;
    float maior = v[0].salario_base + v[0].bonus;

    for(i=0; i<n; i++){
        float maiorAtual = v[i].salario_base + v[i].bonus;

        if(maiorAtual > maior){
            maior = maiorAtual;
            indice = i;
        }

    }

    return indice;
}

int main() {
    int n, i;

    printf("Digite a quantidade de funcionarios: ");
    scanf("%d", &n);

    Funcionario vetF[n];

    for(i=0; i<n; i++){
        printf("Informacoes do %d funcionario: \n", i+1);
        printf("\tDigite o nome do funcionario: ");
        scanf(" %49[^\n]", vetF[i].nome);

        printf("\tDigite o salario do funcionario: ");
        scanf("%f", &vetF[i].salario_base);

        printf("\tDigite o bonus: ");
        scanf("%f", &vetF[i].bonus);
    }

    int r = buscar_maior_total(vetF, n);

    printf("Funcionario com o maior salario: %s\n", vetF[r].nome);
    printf("seu salario: R$ %.2f\n", vetF[r].salario_base);
    printf("Bonus: R$ %.2f\n", vetF[r].bonus);

    return 0;
}