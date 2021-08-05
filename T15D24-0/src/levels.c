#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "levels.h"
#include "shared.h"

int levelsRead(FILE* fp) {
    int flag = 1, inFlag = 0;
    level* new = NULL;
    fseek(fp, 0, SEEK_SET);
    new = (level*)malloc(sizeof(level));
    while (!feof(fp) && !ferror(fp)) {
        inFlag = 1;
        if (fread(new, sizeof(level), 1, fp) == 1) {
            levelsPrint(new);
        }
    }
    if (inFlag == 0 || flag == 0) printf("n/a");
    return flag;
}

void levelsPrint(level* one) {
    printf("%d %d %d\n", one->memLvl, one->memCount, one->secFlag);
}

void levelsWrite(FILE* fp, int ind, level* one) {
    fseek(fp, ind * sizeof(level), SEEK_SET);
    fwrite(one, sizeof(level), 1, fp);
}

level* levelsSelect(FILE* fp, int id) {
    int inFlag = 0, endFlag = 0;
    level* new = NULL;
    fseek(fp, 0, SEEK_SET);
    new = (level*)malloc(sizeof(level));
    while (!feof(fp) && !ferror(fp) && !endFlag) {
        inFlag = 1;
        if (fread(new, sizeof(level), 1, fp) == 1) {
            if (new->memLvl == id) endFlag = 1;
        }
    }
    return new;
}

int levelsUpdate(FILE* fp, int id, level* entity) {
    int inFlag = 0, endFlag = 0, i = 0;
    level* new = NULL;
    fseek(fp, 0, SEEK_SET);
    new = (level*)malloc(sizeof(level));
    while (!feof(fp) && !ferror(fp) && !endFlag) {
        if (fread(new, sizeof(level), 1, fp) == 1) {
            inFlag = 1;
            if (new->memLvl == id) {
                levelsWrite(fp, i, entity);
            }
            i++;
        }
    }
    free(new);
    return inFlag;
}
int levelsInsert(FILE* fp, level* entity) {
    int inFlag = 0;
    level* new = NULL;
    new = (level*)malloc(sizeof(level));
    fseek(fp, 0L, SEEK_END);
    long sz = ftell(fp) / (sizeof(level));
    fseek(fp, 0L, SEEK_END);
    levelsWrite(fp, sz, entity);
    free(new);
    return inFlag;
}

int levelsDelete(FILE* fp, int id, char* fileName) {
    int inFlag = 0, endFlag = 0, i = 0;
    level* new = NULL;
    char* name = filePath(fileName);
    new = (level*)malloc(sizeof(level));
    fseek(fp, 0L, SEEK_END);
    long sz = ftell(fp) / (sizeof(level));
    fseek(fp, 0L, SEEK_SET);
    while (!feof(fp) && !ferror(fp) && !endFlag) {
        inFlag = 1;
        if (fread(new, sizeof(level), 1, fp) == 1) {
            if (new->memLvl == id) {
                levelsShift(fp, i, sz);
                sz--;
                printf("S%ld\n", sz);
                truncate(name, sz * sizeof(level));
            }
            i++;
        }
    }
    free(new);
    return inFlag;
}
void levelsShift(FILE* fp, int ind, int len) {
    level one;
    for (int i = ind; i < len - 1; i++) {
        for (int j = 0; j < 8; j++) {
            fseek(fp, (i + 1) * sizeof(level), SEEK_SET);
            fread(&one, sizeof(level), 1, fp);
        }
        levelsWrite(fp, i, &one);
    }
}
