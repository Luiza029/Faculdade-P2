#include <stdio.h>

char* maiorSubstringVogais(char *S, int *maior) {
    int atual = 0;   
    *maior = 0;  

    char *p = S;
    char *indice_atual = S;
    char *indice_maior = S;

    while(*p != '\0'){    
            if(*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' ||*p == 'u'){
                if(atual == 0){
                    indice_atual = p;
                }

                atual++;

                if(atual > *maior){
                    *maior = atual;
                    indice_maior = indice_atual;
                }
            } else{
                atual = 0;
            }

        p++;
    }
    return indice_maior; 
}

char* copiar(char *saida, char *S, int n) {
    char *inicio_saida = saida;

    for (int i = 0; i < n; i++) {
        *saida = *S;
        saida++;
        S++;
    }
    *saida = '\0';

    return inicio_saida;
}


int main(void) {

    char str[100];
    char saida[100];

    fgets(str,99,stdin);

    int tamanho; 
    char *inicio = maiorSubstringVogais(str, &tamanho);

    printf("%d",tamanho);

    copiar(saida,inicio, tamanho);
    printf("\n%s\n",saida);

    return 0;

}