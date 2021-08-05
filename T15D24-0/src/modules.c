#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "modules.h"
#include "shared.h"

int modulesRead(FILE* fp) {
    int flag = 1, inFlag = 0;
    module* new = NULL;
    fseek(fp, 0, SEEK_SET);
    new = (module*)malloc(sizeof(module));
    while (!feof(fp) && !ferror(fp)) {
        inFlag = 1;
        if (fread(new, sizeof(module), 1, fp) == 1) {
            modulesPrint(new);
        }
    }
    if (inFlag == 0 || flag == 0) printf("n/a");
    return flag;
}
void modulesPrint(module* one) {
    printf("%d %s %d %d %d\n", one->id, one->name, one->memLvl, one->memNum, one->delFlag);
}

void modulesWrite(FILE* fp, int ind, module* one) {
    fseek(fp, ind * sizeof(module), SEEK_SET);
    fwrite(one, sizeof(module), 1, fp);
}

module* modulesSelect(FILE* fp, int id) {
    int inFlag = 0, endFlag = 0;
    module* new = NULL;
    fseek(fp, 0, SEEK_SET);
    new = (module*)malloc(sizeof(module));
    while (!feof(fp) && !ferror(fp) && !endFlag) {
        inFlag = 1;
        if (fread(new, sizeof(module), 1, fp) == 1) {
            if (new->id == id) endFlag = 1;
        }
    }
    return new;
}

int modulesUpdate(FILE* fp, int id, module* entity) {
    int inFlag = 0, endFlag = 0, i = 0;
    module* new = NULL;
    fseek(fp, 0, SEEK_SET);
    new = (module*)malloc(sizeof(module));
    while (!feof(fp) && !ferror(fp) && !endFlag) {
        if (fread(new, sizeof(module), 1, fp) == 1) {
            inFlag = 1;
            if (new->id == id) {
                modulesWrite(fp, i, entity);
            }
            i++;
        }
    }
    free(new);
    return inFlag;
}
int modulesInsert(FILE* fp, module* entity) {
    int inFlag = 0;
    module* new = NULL;
    new = (module*)malloc(sizeof(module));
    fseek(fp, 0L, SEEK_END);
    long sz = ftell(fp) / (sizeof(module));
    fseek(fp, 0L, SEEK_END);
    modulesWrite(fp, sz, entity);
    free(new);
    return inFlag;
}

int modulesDelete(FILE* fp, int id, char* fileName) {
    int inFlag = 0, endFlag = 0, i = 0;
    module* new = NULL;
    char* name = filePath(fileName);
    new = (module*)malloc(sizeof(module));
    fseek(fp, 0L, SEEK_END);
    long sz = ftell(fp) / (sizeof(module));
    fseek(fp, 0L, SEEK_SET);
    while (!feof(fp) && !ferror(fp) && !endFlag) {
        inFlag = 1;
        if (fread(new, sizeof(module), 1, fp) == 1) {
            if (new->id == id) {
                moduleShift(fp, i, sz);
                sz--;
                printf("S%ld\n", sz);
                truncate(name, sz * sizeof(module));
            }
            i++;
        }
    }
    free(new);
    return inFlag;
}

void moduleShift(FILE* fp, int ind, int len) {
    module one;
    for (int i = ind; i < len - 1; i++) {
        for (int j = 0; j < 8; j++) {
            fseek(fp, (i + 1) * sizeof(module), SEEK_SET);
            fread(&one, sizeof(module), 1, fp);
        }
        modulesWrite(fp, i, &one);
    }
}
