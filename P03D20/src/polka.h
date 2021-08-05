#ifndef SRC_POLKA_H_
#define SRC_POLKA_H_

list* convertToPolka(char* str, int len);
int isUnar(char c, int k, list* node);
int isOperator(char c, char* operators);
double polkaCalc(list* node, double x);

#endif  // SRC_POLKA_H_
