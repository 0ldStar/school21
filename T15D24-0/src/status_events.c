#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "modules.h"
#include "status_events.h"
#include "shared.h"

int statusRead(FILE* fp) {
    int flag = 1, inFlag = 0;
    status* new = NULL;
    fseek(fp, 0, SEEK_SET);
    new = (status*)malloc(sizeof(status));
    while (!feof(fp) && !ferror(fp)) {
        inFlag = 1;
        if (fread(new, sizeof(status), 1, fp) == 1) {
            statusPrint(new);
        }
    }
    if (inFlag == 0 || flag == 0) printf("n/a");
    return flag;
}

void statusPrint(status* one) {
    printf("%d %d %d %s %s\n", one->eventId, one->moduleId, one->newStatus, one->date, one->time);
}

void statusWrite(FILE* fp, int ind, status* one) {
    fseek(fp, ind * sizeof(status), SEEK_SET);
    fwrite(one, sizeof(status), 1, fp);
}

status* statusSelect(FILE* fp, int id) {
    int inFlag = 0, endFlag = 0;
    status* new = NULL;
    fseek(fp, 0, SEEK_SET);
    new = (status*)malloc(sizeof(status));
    while (!feof(fp) && !ferror(fp) && !endFlag) {
        inFlag = 1;
        if (fread(new, sizeof(status), 1, fp) == 1) {
            if (new->eventId == id) endFlag = 1;
        }
    }
    return new;
}

int statusUpdate(FILE* fp, int id, status* entity) {
    int inFlag = 0, endFlag = 0, i = 0;
    status* new = NULL;
    fseek(fp, 0, SEEK_SET);
    new = (status*)malloc(sizeof(status));
    while (!feof(fp) && !ferror(fp) && !endFlag) {
        if (fread(new, sizeof(status), 1, fp) == 1) {
            inFlag = 1;
            if (new->eventId == id) {
                statusWrite(fp, i, entity);
            }
            i++;
        }
    }
    free(new);
    return inFlag;
}
int statusInsert(FILE* fp, status* entity) {
    int inFlag = 0;
    status* new = NULL;
    new = (status*)malloc(sizeof(status));
    fseek(fp, 0L, SEEK_END);
    long sz = ftell(fp) / (sizeof(status));
    fseek(fp, 0L, SEEK_END);
    statusWrite(fp, sz, entity);
    free(new);
    return inFlag;
}

int statusDelete(FILE* fp, int id, char* fileName) {
    int inFlag = 0, endFlag = 0, i = 0;
    status* new = NULL;
    char* name = filePath(fileName);
    new = (status*)malloc(sizeof(status));
    fseek(fp, 0L, SEEK_END);
    long sz = ftell(fp) / (sizeof(status));
    fseek(fp, 0L, SEEK_SET);
    while (!feof(fp) && !ferror(fp) && !endFlag) {
        inFlag = 1;
        if (fread(new, sizeof(status), 1, fp) == 1) {
            if (new->eventId == id) {
                statusShift(fp, i, sz);
                sz--;
                printf("S%ld\n", sz);
                truncate(name, sz * sizeof(status));
            }
            i++;
        }
    }
    free(new);
    return inFlag;
}
void statusShift(FILE* fp, int ind, int len) {
    status one;
    for (int i = ind; i < len - 1; i++) {
        for (int j = 0; j < 8; j++) {
            fseek(fp, (i + 1) * sizeof(status), SEEK_SET);
            fread(&one, sizeof(status), 1, fp);
        }
        statusWrite(fp, i, &one);
    }
}
