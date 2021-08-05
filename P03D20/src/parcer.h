#ifndef SRC_PARCER_H_
#define SRC_PARCER_H_

void output(char* str);
int input(char** strIn, int* len);
void shift(char* str, int* len, int ind, int step);
int sinCheck(char* str, int* len, int ind);
int cosCheck(char* str, int* len, int ind);
int lnCheck(char* str, int* len, int ind);
int tgCheck(char* str, int* len, int ind);
int format(char* str, int* len);
int valid(char c);

#endif  // SRC_PARCER_H_
