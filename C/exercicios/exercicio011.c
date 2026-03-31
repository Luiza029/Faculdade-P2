#include <stdio.h>

int soma (int x, int y){
    int restposta = x + y;
    return restposta;
}

int main(){
    int x = 2, y = 3;
    printf("%d", soma(x,y));
    return 0;
}