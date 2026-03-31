#include <stdio.h>

int main(){
    int i, soma = 0, qtd = 0;
    float media, n;

    for (i=0; i<6; i++){
        scanf("%f", &n);

        if(n > 0){
            qtd++;
            soma += n;
            media = soma / qtd;
        }
    }

    printf("A quantidade de positivos eh: %d\n", qtd);
    printf("Media = %.2f", media);

    return 0;
}