#include <stdio.h>
#include "modules_db.h"
#include "modules.h"
#include "levels.h"
#include "status_events.h"
#include "shared.h"

int main() {
    // UI();
    quest();
    return 0;
}

void UI() {
    FILE* fp = NULL;
    int mode;
    mode = menu();
    if (mode == 1) {
        fOpen("materials/master_modules.db", &fp);
        module new;
        mode = subMenu();
        if (mode == 1) {
            if (modelInsertMenu(&new)) {
            modulesInsert(fp, &new);
            } else {
                printf("Invalid input");
            }
        } else if (mode == 2) {
            int id;
            if (updateMenu(&id)) {
            new = *modulesSelect(fp, id);
            printfModule(&new);
            } else {
                printf("Invalid input");
            }
        } else if (mode == 3) {
            int id;
            if (modelInsertMenu(&new) && updateMenu(&id)) {
            modulesUpdate(fp, id, &new);
            } else {
                printf("Invalid input");
            }
        } else if (mode == 4) {
            int id;
            if (updateMenu(&id)) {
            if (!modulesDelete(fp, id, "materials/master_modules.db")) {
                printf("Object not found\n");
            }
            } else {
                printf("Invalid input/n");
            }
        } else if (mode == 5) {
            modulesRead(fp);
        }
        fclose(fp);
    } else if (mode == 2) {
        fOpen("materials/master_levels.db", &fp);
        level new;
        mode = subMenu();
        if (mode == 1) {
            if (levelInsertMenu(&new)) {
            levelsInsert(fp, &new);
            } else {
                printf("Invalid input");
            }
        } else if (mode == 2) {
            int id;
            if (updateMenu(&id)) {
            new = *levelsSelect(fp, id);
            printfLevel(&new);
            } else {
                printf("Invalid input");
            }
        } else if (mode == 3) {
            int id;
            if (levelInsertMenu(&new) && updateMenu(&id)) {
            levelsUpdate(fp, id, &new);
            } else {
                printf("Invalid input");
            }
        } else if (mode == 4) {
            int id;
            if (updateMenu(&id)) {
            if (!modulesDelete(fp, id, "materials/master_levels.db")) {
                printf("Object not found\n");
            }
            } else {
                printf("Invalid input/n");
            }
        } else if (mode == 5) {
            levelsRead(fp);
        }
    } else if (mode == 3) {
        fOpen("materials/master_status_events.db", &fp);
        status new;
        mode = subMenu();
        if (mode == 1) {
            if (statusInsertMenu(&new)) {
            statusInsert(fp, &new);
            } else {
                printf("Invalid input");
            }
        } else if (mode == 2) {
            int id;
            if (updateMenu(&id)) {
            new = *statusSelect(fp, id);
            printfStatus(&new);
            } else {
                printf("Invalid input");
            }
        } else if (mode == 3) {
            int id;
            if (statusInsertMenu(&new) && updateMenu(&id)) {
            statusUpdate(fp, id, &new);
            } else {
                printf("Invalid input");
            }
        } else if (mode == 4) {
            int id;
            if (updateMenu(&id)) {
            if (!modulesDelete(fp, id, "materials/master_status_events.db")) {
                printf("Object not found\n");
            }
            } else {
                printf("Invalid input/n");
            }
        } else if (mode == 5) {
            statusRead(fp);
        }
    }
}

int menu() {
    int menuFlag, mode;

    menuFlag = 1;
    while (menuFlag) {
        printMainMessage();
        int c;
        scanf("%d", &mode);
        if (mode >= -1 && mode <= 3 && mode != 0) {
            menuFlag = 0;
        } else {
            while ((c = getchar()) != '\n') {}
        }
    }
    return mode;
}

int subMenu() {
    int subMenuFlag = 1, mode, c;
    while (subMenuFlag) {
        printOperationMessage();
        scanf("%d", &mode);
        if (mode >= -1 && mode <= 5 && mode != 0) {
            subMenuFlag = 0;
        } else {
            while ((c = getchar()) != '\n') {}
        }
    }
    return mode;
}

void quest() {
    FILE* fp = NULL;
    fOpen("materials/master_modules.db", &fp);
    anulatorModule(fp);
    modulesRead(fp);
    fclose(fp);
    fOpen("materials/master_status_events.db", &fp);
    anulatorStatus(fp);
    statusRead(fp);
    fclose(fp);
    fOpen("materials/master_levels.db", &fp);
    anulatorLevel(fp);
    levelsRead(fp);
    fclose(fp);
}
