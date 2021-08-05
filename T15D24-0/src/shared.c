#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shared.h"
#include "modules.h"
#include "levels.h"
#include "status_events.h"


char* filePath(char* fileName) {
    char path[] = "../";
    static char name[100];
    snprintf(name, strlen(path) + 1, "%s", path);
    strncat(name, fileName, strlen(fileName));
    return name;
}

int fOpen(char* fileName, FILE** fp) {
    int flag, inFlag;
    char* name;
    name = filePath(fileName);
    flag = 1; inFlag = 0;
    if ((*fp = fopen(name, "r+b")) == NULL) {
        flag = 0;
    }
    return flag;
}

void printMainMessage() {
    for (int i = 0; i < 50; i++) printf("#");
    printf("\n                MENU\n");
    printf("Which data base you want to work? '1-3/-1(Exit)'\n");
    printf("1- Modules\n");
    printf("2- Levels\n");
    printf("3- Status Events\n");
    printf("-1 - Exit\n");
    for (int i = 0; i < 50; i++) printf("#");
}

void printOperationMessage() {
    for (int i = 0; i < 50; i++) printf("#");
    printf("\n                MENU\n");
    printf("Which data base you want to work? '1-3/-1(Exit)'\n");
    printf("1- Insert\n");
    printf("2- Select\n");
    printf("3- Update\n");
    printf("4- Delete\n");
    printf("5- Print all table\n");
    printf("-1 - Exit\n");
    for (int i = 0; i < 50; i++) printf("#");
}

int modelInsertMenu(module* new) {
    int flag = 0;
    printf("Input values:");
    printf("\nID");
    flag += scanf("%d", &new->id);
    printf("\nName[30]");
    flag += scanf("%s", new->name);
    printf("\nMemLvl");
    flag += scanf("%d", &new->memLvl);
    printf("\nMemNum");
    flag += scanf("%d", &new->memNum);
    printf("\ndeleteFlag");
    flag += scanf("%d", &new->delFlag);
    return flag / 5;
}

int levelInsertMenu(level* new) {
    int flag = 0;
    printf("Input values:");
    printf("\nMemory lvl");
    flag += scanf("%d", &new->memLvl);
    printf("\nMemory Count");
    flag += scanf("%d", &new->memCount);
    printf("\nSecurity Flag");
    flag += scanf("%d", &new->secFlag);
    return flag / 3;
}

int statusInsertMenu(status* new) {
    int flag = 0;
    printf("Input values:");
    printf("\nEvent id");
    flag += scanf("%d", &new->eventId);
    printf("\nModule id");
    flag += scanf("%d", &new->moduleId);
    printf("\nNew status");
    flag += scanf("%d", &new->newStatus);
    printf("\nDate[10]");
    flag += scanf("%s", new->date);
    printf("\nTime[8]");
    flag += scanf("%s", new->time);
    return flag / 3;
}

int updateMenu(int* id) {
    int flag;
    printf("Input id object to change ");
    flag = scanf("%d", id);
    return flag;
}

void printfModule(module* new) {
    printf("ID %d\n", new->id);
    printf("Name %s\n", new->name);
    printf("MemLvl %d\n", new->memLvl);
    printf("MemNum %d\n", new->memNum);
    printf("ndeleteFlag %d\n", new->delFlag);
}

void printfLevel(level* new) {
    printf("Memory lvl %d\n", new->memLvl);
    printf("Memory Count %d\n", new->memCount);
    printf("Security Flag %d\n", new->secFlag);
}

void printfStatus(status* new) {
    printf("Event id %d\n", new->eventId);
    printf("Module id %d\n", new->moduleId);
    printf("New status %d\n", new->newStatus);
    printf("Date %s\n", new->date);
    printf("Time %s\n", new->time);
}

void anulatorModule(FILE* fp) {
    int flag = 1, inFlag = 0;
    module* new = NULL;
    fseek(fp, 0, SEEK_SET);
    new = (module*)malloc(sizeof(module));
    int i = 0;
    while (!feof(fp) && !ferror(fp)) {
        inFlag = 1;
        if (fread(new, sizeof(module), 1, fp) == 1) {
            if (new->id != 0) {
                new->delFlag = 1;
            } else {
                new->memLvl = 1;
                new->memNum = 1;
            }
            modulesWrite(fp, i, new);
            i++;
        }
    }
    if (inFlag == 0 || flag == 0) printf("n/a");
}

void anulatorStatus(FILE* fp) {
    int flag = 1, inFlag = 0;
    status* new = NULL;
    fseek(fp, 0, SEEK_SET);
    new = (status*)malloc(sizeof(status));
    int i = 0;
    while (!feof(fp) && !ferror(fp)) {
        inFlag = 1;
        if (fread(new, sizeof(status), 1, fp) == 1) {
            if (new->moduleId != 0) {
                new->newStatus = 0;
            } else {
                new->newStatus = 0;
                new->newStatus = 1;
                new->newStatus = -20;
            }
            statusWrite(fp, i, new);
            i++;
        }
    }
    if (inFlag == 0 || flag == 0) printf("n/a");
}
void anulatorLevel(FILE* fp) {
    int flag = 1, inFlag = 0;
    level* new = NULL;
    fseek(fp, 0, SEEK_SET);
    new = (level*)malloc(sizeof(level));
    int i = 0;
    while (!feof(fp) && !ferror(fp)) {
        inFlag = 1;
        if (fread(new, sizeof(level), 1, fp) == 1) {
            if (new->memLvl == 1) {
                new->secFlag = 1;
            }
            levelsWrite(fp, i, new);
            i++;
        }
    }
    if (inFlag == 0 || flag == 0) printf("n/a");
}
