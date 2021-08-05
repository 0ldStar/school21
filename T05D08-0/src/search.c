#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int* a, int* n);
double mean(int* a, int n);
double variance(int* a, int n, double mean);
double power(double a, int b);
double sqrt(double number);
void search(int* a, int n);

int main() {
    int n, data[NMAX];
    if (!input(data, &n)) return 0;
    search(data, n);
    return 1;
}

int input(int* a, int* n) {
    if (scanf("%d", n) != 1 || * n > NMAX || *n <= 0) {
        printf("n/a");
        return 0;
    }
    for (int* p = a; p - a < *n; p++) {
        scanf("%d", p);
    }
    return 1;
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
        sum += pow((a[i] - mean), 2);
    }
    return sum / (double)n;
}

void search(int* a, int n) {
    int flag = 0;
    double mean_v = mean(a, n);
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] >= mean_v && (a[i] <= mean_v + 3 *
            sqrt(variance(a, n, mean_v))) && a[i] != 0) {
            printf("%d", a[i]);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("0");
    }
}
