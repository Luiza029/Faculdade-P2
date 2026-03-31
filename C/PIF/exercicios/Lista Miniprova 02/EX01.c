#include <stdio.h>

void contarCaracter(char *str, int *vogais, int *consoantes){

    while(*str != '\0'){
        
        if(*str >= 'a' && *str <= 'z'){ // ele so vai entrar aq, quando for letra, se for espaco ele ignora
            if(*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u'){
                (*vogais)++;
            } else{
                (*consoantes)++;
            }
        }
        
        str++;
    }
}

int main() {
    
    int vogais = 0, consoantes = 0;
    char str[50]; 

    printf("Digite uma palavra: ");
    scanf("%50[^\n]", str);

    contarCaracter(str, &vogais, &consoantes);

    printf("Vogais: %d\n", vogais);
    printf("Consoantes: %d\n", consoantes);

    return 0;
}