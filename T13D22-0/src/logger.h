#ifndef SRC_LOGGER_H_
#define SRC_LOGGER_H_

#include "log_levels.h"
#include <stdio.h>

int log_init(char* filename, FILE** fp);
void addLog(char *message, log_level level, FILE* fp);
void log_close(FILE* fp);

#endif  // SRC_LOGGER_H_
