#include <stdio.h>

int main(){
    int a, b,c;

    printf("Digite o lado A do triangulo: ");
    scanf("%d", &a);
    printf("Digite o lado B do triangulo: ");
    scanf("%d", &b);
    printf("Digite o lado C do triangulo: ");
    scanf("%d", &c);

    if (a == b && b == c){
        printf("Equilatero");
    } else if (a == b || a == c || c == b){ /* ou apenas coloca no else ja que é mais complicado (a != b && b != c)*/
        printf("Isosceles");
    } else{
        printf("Escaleno");
    }
    
    return 0;
}