#include "documentation_module.h"
#include "math.h"
#include <stdarg.h>

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}
short check_available_documentation_module(int (*validate) (char*), int document_count, ...) {
    va_list args;
    char* str;
    short mask;
    int len = 0;

    va_start(args, document_count);
    mask = 0;
    while (document_count--) {
        str = va_arg(args, char*);
        if (validate(str) == 1) {
            mask += pow(2, len);
        }
        len++;
    }

    va_end(args);
    return mask;
}

void print_document_status(short availability_mask, int document_count, ...) {
    va_list args;
    va_start(args, document_count);
    char* str;
    int i = 1;
    printf("\n");
    while (document_count--) {
        str = va_arg(args, char*);
        printf("%d. %-16s", i, str);
        if (availability_mask % 2 == 1){
            printf(" available");
        } else {
            printf(" unavailable");
        }
        if (i < 15) printf("\n");
        i++;
        availability_mask /= 2;
    }
    va_end(args);
}