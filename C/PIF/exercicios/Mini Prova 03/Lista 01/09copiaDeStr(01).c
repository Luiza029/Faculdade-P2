#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copia(char *s){
    int cont = 0;
    char *percorrer = s;
    
    while(*percorrer != '\0'){
        percorrer++;
        cont++;
    }
    
    char *strFinal = (char*) malloc((cont + 1) * sizeof(char));
    char *final = strFinal;

    while(*s != '\0'){
        *strFinal = *s;

        strFinal++;
        s++;
    }

    *strFinal = '\0'; 

    return final;
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
