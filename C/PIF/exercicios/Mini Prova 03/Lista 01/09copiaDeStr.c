#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copia(char *s){
    char *copia = (char*) malloc((strlen(s) + 1) * sizeof(char)); 
    char *inicio = copia;

    while(*s != '\0'){
        *copia = *s;
        s++;
        copia++;
    }

    *copia = '\0';

    return inicio;
}

int main() {
    char str[50];

    printf("Digite sua frase: ");
    scanf("%50[^\n]", str);

    char *r = copia(str);
    printf("%s", r);

    free(r);
    r = NULL;
    return 0;
}