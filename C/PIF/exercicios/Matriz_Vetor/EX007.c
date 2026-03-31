#include <stdio.h>

int Vetor(int vet[], int n, int vetorSaida[]){
    int vetPar[n], vetImpar[n], i, qtd_par = 0, qtd_impar = 0, k =0;

    for(i=0; i<n; i++){
        if(vet[i] % 2 == 0){
            vetPar[qtd_par] = vet[i]; // qunado for atribuit um vetor para o outro no posso usar o I, tenho que usar outra coisa para ter a funcao do i
            qtd_par++;
        }
        else{
            vetImpar[qtd_impar] = vet[i];
            qtd_impar++;
        }
    }

    for(i=0; i<qtd_par; i++){
        vetorSaida[k] = vetPar[i];
        k++;
    }

    for(i=0; i<qtd_impar; i++){
        vetorSaida[k] = vetImpar[i];
        k++;
    }


    return qtd_par;
}

int main(){
    int vet[10] = {9, 6, 1, 2, 3, 8, 5, 4, 7, 10}, n = 10, i;
    int vetorSaida[10]; // para quando sair da funcao o vetor nao sumir
    int pares = Vetor(vet, n, vetorSaida);

    printf("Quantidade de pares %d\n", pares);
    for(i=0; i<n; i++){
        printf("%d, ", vetorSaida[i]);
    }
    return 0;
}