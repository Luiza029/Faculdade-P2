#include <stdio.h>

void Media(float A, float B, float *media, float *soma){
    *soma = A + B;
    *media = *soma / 2;
}

int main(){
    float media, soma;
    float A = 6.5, B = 7.2;

    Media(A, B, &media, &soma);
    printf("Soma: %.1f \t|\t Media: %.1f", soma, media);
    return 0;
}