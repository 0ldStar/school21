#include <stdio.h>
int fib();

int main() {
    int n;
    char c;

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("n/a");
        return 0;
    }
    if (scanf("%c", &c) != 0 && c != '\n') {
        printf("n/a");
        return 0;
    }

    printf("%d", fib(n));
    return 0;
}
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
