int VetorPeso(int n, float m[n][n], float vetpeso[]);

int main(){
    int n = 3;
    float mat[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    float vetPeso[3] = {9, 6, 2}; 
    
    printf("Indice da menor coluna: %d\n", VetorPeso(n, mat, vetPeso));
    
    return 0;
}

int VetorPeso(int n, float m[n][n], float vetpeso[]){
    int i, j;
    float menorSoma, soma;
    int indiceMenor;

    for(j = 0; j < n; j++){
        soma = 0;
        for(i = 0; i < n; i++){
            soma += m[i][j] * vetpeso[i];
        }

        if(j == 0){
            indiceMenor = j;
            menorSoma = soma;
        } else if(soma < menorSoma){
            menorSoma = soma;
            indiceMenor = j;
        }
    }
    
    return indiceMenor;
}