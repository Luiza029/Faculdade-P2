#include <stdio.h>
#include <math.h>

typedef struct Ponto{
    int x;
    int y;
} Ponto;

typedef struct Retangulo{
    Ponto pt1;
    Ponto Pt2;
} Rect;

int main() {
    Rect r;

    r.pt1.x = 1;
    r.pt1.y = 2;

    r.Pt2.x = 3;
    r.Pt2.y = 4;

    double base = abs();

    return 0;
}