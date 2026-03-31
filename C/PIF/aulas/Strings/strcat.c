// Juntar duas strings

#include <stdio.h>
#include <string.h>

int main(){
    char vet1[50] = {"Ola"};
    char vet2[50] = {"Mundo"};

    printf("Vet1: %s\n", vet1);
    printf("Vet2: %s\n", vet2);

    strcat(vet1, vet2);

    printf("Vet1: %s\n", vet1);
    printf("Vet2: %s\n", vet2);
    
    return 0;
}