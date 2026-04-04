#include <stdio.h>

typedef struct{
    int dia, mes, ano;
}Data;

void imprimir(Data data){
    printf("Data: %d/%d/%d\n", data.dia, data.mes, data.ano);
}

void imprimirDataPonteiro(Data *data){
    printf("Data: %d/%d/%d", data->dia, data->mes, data->ano);
}

Data preencherData(){
    Data d;

    d.dia = 10;
    d.mes = 12;
    d.ano = 14;

    return d;
}

void preencherDataPonteiro(Data *d){
    d->dia = 10;
    d->mes = 12;
    d->ano = 14;
}

int main() {

    Data data;

    //data = preencherData();

    dpreencherDataPonteiro(&data);
    
    imprimir(data);
    imprimirDataPonteiro(&data);
    return 0;
}