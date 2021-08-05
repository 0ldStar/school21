#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    char str[10];
    struct list* next;
    struct list* prev;
} list;

typedef struct stack {
    double num;
    struct stack* next;
} stack;

void init(list** head);
void push(list** head, char *str, int len);
char* popNext(list** head);
char* popPrev(list** head);
void destroy(list** head);
list* getPrev(list* node);
double popStack(stack** head);
void pushStack(stack** head, double num);
void destroyStack(stack** head);

#endif  // SRC_STACK_H_
