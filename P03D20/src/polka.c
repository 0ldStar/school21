#include "stack.h"
#include <stdio.h>
#include <string.h>
#include "polka.h"
#include <math.h>
/*
c - cos
s - sin
t - tg
g - ctg
q - sqrt
l - ln
*/

list* convertToPolka(char* str, int len) {
    list* head = NULL, * node = NULL;
    char str1[10];
    int j;

    init(&head);
    init(&node);
    for (int i = 0; i < len; i++) {
        int ch = 0;
        if (str[i] >= '0' && str[i] <= '9' || str[i] == 'x' || isUnar(str[i], i, head)) {
            if (isUnar(str[i], i, head) == 1) {
                ch = 1;
            }
            str1[0] = str[i];
            j = 1;
            while (str[i + j] >= '0' && str[i + j] <= '9' || str[i + j] == 'x') {
                str1[j] = str[i + j];
                j++;
            }
            str1[j] = '\0';
            push(&node, str1, j);
            i = i + j - 1;
        }
        if (isOperator(str[i], "cstgql")) {
            str1[0] = str[i];
            push(&head, &str1[0], 1);
        }
        if (str[i] == '(') {
            str1[0] = str[i];
            push(&head, &str1[0], 1);
        }
        if (str[i] == ')') {
            while (head->str[0] != '(') push(&node, popNext(&head), 1);
            popNext(&head);
        }
        if (isOperator(str[i], "-+") && ch == 0) {
            while (head != NULL && isOperator(head->str[0], "cstgql*/^")) {
                push(&node, popNext(&head), 1);
            }
            str1[0] = str[i];
            push(&head, &str1[0], 1);
        }
        if (isOperator(str[i], "*/")) {
            while (head != NULL && isOperator(head->str[0], "cstgql^")) {
                push(&node, popNext(&head), 1);
            }
            str1[0] = str[i];
            push(&head, &str1[0], 1);
        }
        if (str[i] == '^') {
            while (head != NULL && isOperator(head->str[0], "cstgql")) {
                push(&node, popNext(&head), 1);
            }
            str1[0] = str[i];
            push(&head, &str1[0], 1);
        }
    }
    while (head != NULL) {
        push(&node, popNext(&head), 1);
    }
    destroy(&head);
    return node;
}

int isOperator(char c, char* operators) {
    int s, len;
    s = 0; len = strlen(operators);
    for (int i = 0; i < len; i++) {
        s += (c == operators[i]) ? 1 : 0;
    }
    return s;
}

int isUnar(char c, int k, list* node) {
    int s = 0;
    if ((k == 0 && c == '-') || (c == '-' && node && (node->str[0] == '('
    || isOperator(node->str[0], "^cstgql")))) {
        s = 1;
    }
    return s;
}

double polkaCalc(list* node, double x) {
    double rez, buf;
    double num;

    num = 0; rez = 0;
    list* hSave;
    stack* head;
    hSave = node;
    head = NULL;
    while (node != NULL) {
        if (node->str[0] == '-' && node->str[1] >= '0' && node->str[1] <= '9') {
            num = 0;
            for (int i = 1; node->str[i] != '\0'; i++) {
                num *= 10;
                num += node->str[i] - '0';
            }
            num = -num;
            pushStack(&head, num);
        }
        if (node->str[0] >= '0' && node->str[0] <= '9') {
            num = 0;
            for (int i = 0; node->str[i] != '\0'; i++) {
                num *= 10;
                num += node->str[i] - '0';
            }
            pushStack(&head, num);
        }
        if (node->str[0] == 'x') {
            pushStack(&head, x);
        }
        switch (node->str[0]) {
        case '+':
            rez = popStack(&head) + popStack(&head);
            pushStack(&head, rez);
            break;
        case '-':
            if (node->str[1] >= '0' && node->str[1] <= '9') {
                num = 0;
                for (int i = 1; node->str[i] != '\0'; i++) {
                    num *= 10;
                    num += node->str[i] - '0';
                }
                num = -num;
                pushStack(&head, (double)num);
            } else if (node->str[1] == 'x') {
                pushStack(&head, -x);
            } else {
            rez = -popStack(&head) + popStack(&head);
            pushStack(&head, rez);
            }
            break;
        case '*':
            rez = popStack(&head) * popStack(&head);
            pushStack(&head, rez);
            break;
        case '/':
            rez = 1 / popStack(&head) * popStack(&head);
            pushStack(&head, rez);
            break;
        case '^':
            buf = popStack(&head);
            rez = pow(popStack(&head), buf);
            pushStack(&head, rez);
            break;
        case 's':
            rez = sin(popStack(&head));
            pushStack(&head, rez);
            break;
        case 'c':
            rez = cos(popStack(&head));
            pushStack(&head, rez);
            break;
        case 't':
            rez = tan(popStack(&head));
            pushStack(&head, rez);
            break;
        case 'g':
            rez = 1 / tan(popStack(&head));
            pushStack(&head, rez);
            break;
        case 'q':
            rez = sqrt(popStack(&head));
            pushStack(&head, rez);
            break;
        case 'l':
            rez = log(popStack(&head));
            pushStack(&head, rez);
            break;
        default:
            break;
        }
        node = node->prev;
    }
    rez = popStack(&head);
    destroyStack(&head);
    return rez;
}
