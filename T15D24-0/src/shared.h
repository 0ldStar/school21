#ifndef SRC_SHARED_H_
#define SRC_SHARED_H_

#include "status_events.h"
#include "modules.h"
#include "levels.h"
#define insert(db, x) _Generic((x), \
  module *  : modulesInsert, \
  status *  : statusInsert, \
  level * : levelsInsert \
)(db, x)

#define update(db, ind, x) _Generic((x), \
  module *  : modulesUpdate, \
  status *  : statusUpdate, \
  level * : levelsUpdate \
)(db, ind, x)

char* filePath(char* fileName);
int fOpen(char* fileName, FILE** fp);
void printMainMessage();
void printOperationMessage();
int modelInsertMenu(module* new);
int levelInsertMenu(level* new);
int statusInsertMenu(status* new);
int updateMenu(int* id);
void printfModule(module* new);
void printfLevel(level* new);
void printfStatus(status* new);
void anulatorStatus(FILE* fp);
void anulatorModule(FILE* fp);
void anulatorLevel(FILE* fp);

#endif  // SRC_SHARED_H_
