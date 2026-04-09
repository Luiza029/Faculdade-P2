#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float x;
    float y;
} Ponto;

typedef struct{
    Ponto p1;
    Ponto p2;
} Retangulo;

float area_retangulo(Retangulo r){
    float base = fabsf(r.p2.x - r.p1.x);
    float altura = fabsf(r.p2.y - r.p1.y);
    float resultado = base * altura;

    return resultado;
}

int contar_retangulos_maiores(Retangulo v[], int n, float valor){
    int i, cont = 0;
    
    for(i=0; i<n; i++){
        float area = area_retangulo(v[i]); 
        if(area > valor){
            cont++;
        }
    }

    return cont;
}

int main() {
    int n, i;
    float valor;

    printf("Digite o tamanho n: ");
    scanf("%d", &n);

    Retangulo vetR[n];

    for(i=0; i<n; i++){
        printf("Retangulo %d: \n", i+1);
        printf("Digite o valor de X1 e X2: ");
        scanf("%f %f", &vetR[i].p1.x, &vetR[i].p2.x);

        printf("Digite o valor de Y1 e Y2: ");
        scanf("%f %f", &vetR[i].p1.y, &vetR[i].p2.y);
    }

    printf("Digite um valor para comparar: ");
    scanf("%f", &valor);

    int r = contar_retangulos_maiores(vetR, n, valor);

    printf("Qtd de retangulos maiores que %.1f: %d", valor, r);
    return 0;
}