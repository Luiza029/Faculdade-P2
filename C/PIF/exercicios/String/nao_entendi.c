/*
Exercício 10 — Remover palavras duplicadas

- Crie uma função que:
    - receba uma string (char *str)
    - remova palavras repetidas
    - mantendo apenas a primeira ocorrência

📌 Protótipo:
void removerPalavrasRepetidas(char *str);

🔹 Exemplos:
"ana gosta de ana" → "ana gosta de"
"eu eu eu estudo"  → "eu estudo"
"casa azul casa"   → "casa azul"

⚠️ Regras
❌ não pode usar []
❌ não pode usar strcmp, strcpy, etc.
✔ só ponteiros
✔ modificar a string original
*/

#include <stdio.h>

// compara duas palavras
int iguais(char *p1, char *p2){
    while(*p1 == *p2 && *p1 != ' ' && *p1 != '\0'){
        p1++;
        p2++;
    }

    if((*p1 == ' ' || *p1 == '\0') &&
       (*p2 == ' ' || *p2 == '\0')){
        return 1;
    }

    return 0;
}

void removerPalavrasRepetidas(char *str){
    char *leitor = str;
    char *escritor = str;

    while(*leitor != '\0'){

        // pular espaços
        while(*leitor == ' '){
            leitor++;
        }

        if(*leitor == '\0') break;

        char *inicioAtual = leitor;

        // achar fim da palavra atual
        while(*leitor != ' ' && *leitor != '\0'){
            leitor++;
        }

        char *fimAtual = leitor;

        int repetida = 0;

        // verificar palavras anteriores
        char *p = str;

        while(p < escritor){
            while(*p == ' ') p++;

            char *inicioAntiga = p;

            while(*p != ' ' && *p != '\0'){
                p++;
            }

            char *fimAntiga = p;

            if(iguais(inicioAtual, inicioAntiga)){
                repetida = 1;
                break;
            }
        }

        // se não for repetida, copia
        if(!repetida){
            char *temp = inicioAtual;

            while(temp < fimAtual){
                *escritor = *temp;
                escritor++;
                temp++;
            }

            *escritor = ' ';
            escritor++;
        }
    }

    // remove espaço final
    if(escritor != str){
        escritor--;
    }

    *escritor = '\0';
}

int main(){
    char str[] = "ana gosta de ana gosta";

    removerPalavrasRepetidas(str);

    printf("%s\n", str);

    return 0;
}