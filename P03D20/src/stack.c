#include <stdlib.h>
#include "stack.h"
#include <string.h>

void init(list** head) {
    *head =  NULL;
}

void push(list** head, char* str, int len) {
    list* tmp = (list*)malloc(sizeof(list));
    for (int i = 0; i < len; i++) {
        tmp->str[i] = str[i];
    }
    tmp->str[len] = '\0';
    tmp->next = (*head);
    tmp->prev = NULL;
    if (*head != NULL) (*head)->prev = tmp;
    (*head) = tmp;
}

char* popNext(list** head) {
    static char str[10];
    if (*head == NULL) {
        return NULL;
    } else {
        list* tmp;
        tmp = *head;
        strcpy(str, (*head)->str);
        *head = (*head)->next;
        free(tmp);
    }
    return str;
}

void destroy(list** head) {
    list* tmp = NULL;
    if (head != NULL) {
    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    }
}
void destroyStack(stack** head) {
    stack* tmp = NULL;
    if (head != NULL) {
    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    }
}

list* getPrev(list* node) {
    while (node->next != NULL) {
        node = node->next;
    }
    return node;
}

void pushStack(stack** head, double num) {
    stack* tmp = (stack*)malloc(sizeof(stack));
    tmp->num = num;
    tmp->next = (*head);
    (*head) = tmp;
}

double popStack(stack** head) {
    double num;
    if (*head == NULL) {
        return 0;
    } else {
        stack* tmp;
        tmp = *head;
        num = tmp->num;
        *head = (*head)->next;
        free(tmp);
    }
    return num;
}
