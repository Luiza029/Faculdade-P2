#include <stdio.h>

void Maiuscula(char *vet){
    int i = 0;

    while(*(vet+i) != '\0'){
        if(*(vet+i) >= 'a' && *(vet+i) <= 'z'){
            *(vet+i) = *(vet+i) - 32;
        }
        i++;
    }
}

int main(){
    char vet[100];

    printf("Digite uma frase: ");
    scanf("%100[^\n]", vet);

    Maiuscula(vet);
    printf("%s", vet);

    return 0;
}