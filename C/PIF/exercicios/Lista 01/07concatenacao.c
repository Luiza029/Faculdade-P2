#include <stdio.h>
#include <stdlib.h>

int main() {
    char vet1[50], vet2[50], *vet3;
    int i = 0, k = 0;

    printf("Digite um frase: ");
    scanf("%50[^\n]", vet1);

    getchar();

    printf("Digite a segunda frase: ");
    scanf("%50[^\n]", vet2);

    vet3 = malloc(101 * sizeof(char)); // adicionar +1 por conta do \0

    while(vet1[i] != '\0'){
        vet3[k] = vet1[i];
        i++;
        k++;
    }

    i = 0;

    while(vet2[i] != '\0'){
        vet3[k] = vet2[i];
        i++;
        k++;
    }

    vet3[k] = '\0';

    printf("%s", vet3);

    free(vet3);
    vet3 = NULL;

    return 0;
}