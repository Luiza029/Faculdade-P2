#include <stdio.h>

void removerRepetido(char *str){
    int i, j, k = 0, repetido = 0;

    for(i=0; *(str+i) != '\0'; i++){
        repetido = 0;
        for(j=0; j<i; j++){
            if(*(str+i) == *(str+j)){
                repetido = 1;
            }
        }

        if(repetido == 0){
            *(str+ k++) = *(str+i);
        }
    }

    *(str+k) = '\0';
}

int main(){
    char str[] = "Banana";

    removerRepetido(str);
    printf("%s", str);
    return 0;
}