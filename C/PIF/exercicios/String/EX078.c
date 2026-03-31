#include <stdio.h> 

int strLen(char *str){
    int cont = 0, i = 0;

    while(*(str+i) != '\0'){
        cont++;
        i++;
    }

    return cont;
}

int main(){
    char str[] = {"Ovo"};

    int r = strLen(str);
    printf("%d", r);
    return 0;
}