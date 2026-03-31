#include <stdio.h>

void removerEspaco(char *str){
    char *leitor = str;
    char *escritor = str;

    while(*leitor != '\0'){
        if(*leitor != ' '){
            *escritor = *leitor;
            escritor++;
        }
        leitor++;
    }

    *escritor = '\0';
}

int main(){
    char str[] = "Amanga Eh Muito Chata";

    removerEspaco(str);
    printf("%s", str);
    return 0;
}