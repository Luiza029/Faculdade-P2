#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mdc(int x, int y){
    if(x % y == 0){
        return y;
    }

    return mdc(y, x % y);
}

int main() {
    printf("%d", mdc(60,18));    
    return 0;
}