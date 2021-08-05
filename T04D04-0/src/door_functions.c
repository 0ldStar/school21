#include <stdio.h>
#include <math.h>

void funcAgnesi();
void funcQuadHyperbola();
void funcLemnisBern();

int main() {
    double pi = 3.141592653589793238462;
    for (double x = -pi; x <= pi; x += 2* pi / 41) {
        printf("%.7lf | ", x);
        funcAgnesi(x);
        funcLemnisBern(x);
        funcQuadHyperbola(x);
    }

    return 0;
}

void funcAgnesi(double x) {
    double y = 1 / (1 + x * x);
    if (y != y || x < 1e-6 && x > 0 || x > 1e-6 && x < 0) {
        printf("- | ");
    } else {
        printf("%.7lf | ", y);
    }
}

void funcLemnisBern(double x) {
    double y = (double)sqrt(sqrt(1 + 4 * x * x) - x * x - 1);
    if (y != y) {
        printf("- | ");
    } else {
        printf("%.7lf | ", y);
    }
}
void funcQuadHyperbola(double x) {
    double y = 1 / (x * x);
    if (y != y || x < 1e-6 && x > 0 || x > 1e-6 && x < 0) {
        printf("-\n");
    } else {
        printf("%.7lf\n", y);
    }
}
