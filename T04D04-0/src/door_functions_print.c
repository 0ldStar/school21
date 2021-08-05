#include <stdio.h>
#include <math.h>

#define WIDTH 42
#define HEIGH 21
#define LIMIT 2147483647

double funcAgnesi();
double funcQuadHyperbola();
double funcLemnisBern();
void graph();

const double pi = 3.141592653589793238462;
int main() {
    graph(funcAgnesi);
    printf("##########################################\n");
    graph(funcLemnisBern);
    printf("##########################################\n");
    graph(funcQuadHyperbola);
    return 0;
}

double funcAgnesi(double x) {
    double y = 1 / (1 + x * x);
    if (y != y || x < 1e-6 && x > 0 || x > 1e-6 && x < 0) {
        return LIMIT;
    } else {
        return y;
    }
}

double funcLemnisBern(double x) {
    double y = (double)sqrt(sqrt(1 + 4 * x * x) - x * x - 1);
    if (y != y) {
        return LIMIT;
    } else {
        return y;
    }
}
double funcQuadHyperbola(double x) {
    double y = 1 / (x * x);
    if (y != y || x < 1e-6 && x > 0 || x > 1e-6 && x < 0) {
        return LIMIT;
    } else {
        return y;
    }
}
void graph(double(*func)()) {
    double max = -LIMIT;
    double y, x = -pi;
    for (int i = 0; i < WIDTH; i++) {
        y = func(x);
        x += 2 * pi / 41;
        if (y > max && y != LIMIT) max = y;
    }
    for (int i = HEIGH; i > 0; i--) {
        x = -pi;
        for (int j = 0; j < WIDTH; j++) {
            y = func(x);
            x += 2 * pi / 41;
            if (y == LIMIT) {
                printf(" ");
                continue;
                }
            if (y >= max / HEIGH * i && y < max / HEIGH * (i + 1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
