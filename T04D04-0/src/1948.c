#include <stdio.h>

int main() {
    int x, flag, tmp, rez;
    scanf("%d", &x);
    if ((x >= 0 && x <= 1) || (x <= 0 && x >= -1)) {
        printf("n/a");
        return 1;
    }
    if (x < 0) x = -x;
    for (int i = 2; i < x; ++i) {
        tmp = x;
        while (tmp > i) {
            tmp -= i;
        }
        if (tmp == i) {
            flag = 1;
            for (int j = 2; j < tmp; j++) {
                int k;
                for (k = 1; k * j < tmp; k++) {}
                if (k * j == tmp) flag = 0;
            }
            if (flag == 1) rez = tmp;
        }
    }
    printf("%d", rez);
    return 1;
}
