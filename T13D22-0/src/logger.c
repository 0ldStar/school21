#include <stdlib.h>
#include <string.h>
#include "log_levels.h"
#include <stdio.h>
#include "logger.h"

int log_init(char* filename, FILE** fp) {
    int flag;

    flag = 1;
    *fp = NULL;
    if ((*fp = fopen(filename, "a+")) == NULL) {
        printf("n/a");
        flag = 0;
    }
    return flag;
}

void addLog(char* message, log_level level, FILE* fp) {
    char buf[100];
    char* logList[] = {"DEBUG  ", "TRACE  ", "INFO  ", "WARNING  ", "ERROR  "};
    snprintf(buf, strlen(logList[level]), "%s", logList[level]);
    strncat(buf, message, strlen(message));
    fprintf(fp, "%s\n", buf);
}
void log_close(FILE* fp) {
    fclose(fp);
}
