#include <math.h>
#include <stdio.h>
#include "graph.h"
#include "plot.h"

void graph(list* node, double(*func)(list* node, double arg)) {
    double y;

    for (int i = 0; i < HEIGHT; i++) {
        double x = 0;
        for (int j = 0; j < WIDTH; j++) {
            y = func(node, x);
            x += 4 * M_PI / (double)WIDTH;
            if (y + LIMIT >= 2 / (double)HEIGHT * i && y + LIMIT <= 2 / (double)HEIGHT * (i + 1)) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}
