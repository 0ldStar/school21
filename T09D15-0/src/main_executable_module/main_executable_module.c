#include "../data_module/data_process.h"
#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../yet_another_decision_module/decision.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    double* data;
    int n = 5;

    data = (double*)malloc(n * sizeof(int));

    printf("LOAD DATA...\n");
    input(data, n);

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, n);
    output(data, n);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    output(data, n);

    printf("\nFINAL DECISION:\n\t");
    make_decision(data, n);
    output(data, n);
    return 0;
}
