#include <stdio.h>
#define NMAX 10

int input(int* a, int* n);
void output(int* a, int n);
int max(int* a, int n);
int min(int* a, int n);
double mean(int* a, int n);
double variance(int* a, int n, double mean);
double power(double a, int b);

void output_result(int max_v,
    int min_v,
    double mean_v,
    double variance_v);

int main() {
    int n, data[NMAX];
    if (!input(data, &n)) return 0;
    output(data, n);
    printf("\n");
    output_result(max(data, n),
        min(data, n),
        mean(data, n),
        variance(data, n, mean(data, n)));
    return 1;
}
double power(double a, int b) {
    double rez = 1;
    for (int i = 0; i < b; i++) {
        rez *= a;
    }
    return rez;
}

int input(int* a, int* n) {
    if (scanf("%d", n) != 1 || *n > NMAX || *n <= 0) {
        printf("n/a");
        return 0;
    }
    for (int* p = a; p - a < *n; p++) {
        scanf("%d", p);
    }
    return 1;
}

void output(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) printf(" ");
    }
}

int min(int* a, int n) {
    int min = *a;
    for (int i = 0; i < n; i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

int max(int* a, int n) {
    int max = *a;
    for (int i = 0; i < n; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

double mean(int* a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / (double)n;
}

double variance(int* a, int n, double mean) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += power((a[i] - mean), 2);
    }
    return sum / (double)n;
}

void output_result(int max_v,
    int min_v,
    double mean_v,
    double variance_v) {
    printf("%d %d %lf %lf", max_v, min_v, mean_v, variance_v);
}

