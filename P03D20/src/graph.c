#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "stack.h"
#include "graph.h"
#include "plot.h"
#include "parcer.h"
#include "polka.h"

int main() {
    char* str;
    int len, flag;
    list* node;

    flag = input(&str, &len);
    if (flag == 1) {
        flag = format(str, &len);
        if (flag == 1) {
            node = convertToPolka(str, len);
            list* prev = getPrev(node);
            graph(prev, polkaCalc);
            destroy(&node);
        }
    }
    free(str);
    if (flag == 0) {
        printf("Invalid input");
    }
    return 0;
}
