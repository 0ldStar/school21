#ifndef SRC_MODULES_H_
#define SRC_MODULES_H_

#include <stdio.h>

typedef struct module {
    int id;
    char name[30];
    int memLvl;
    int memNum;
    int delFlag;
} module;

int modulesRead(FILE* db);
void modulesPrint(module* one);
void modulesWrite(FILE* db, int ind, module* one);
module* modulesSelect(FILE* fp, int id);
int modulesInsert(FILE *db, module *entity);
int modulesUpdate(FILE* fp, int id, module* entity);
int modulesDelete(FILE* fp, int id, char* fileName);
void moduleShift(FILE* fp, int ind, int len);

#endif  // SRC_MODULES_H_
