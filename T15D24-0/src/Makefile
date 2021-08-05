.PHONY: all clean rebuild
FLAGS =-Wall -Werror -Wextra

all: main
main: modules_db.c modules.c levels.c status_events.c shared.c
	gcc $(FLAGS) modules_db.c modules.c status_events.c levels.c shared.c -o ../build/Quest_1
clean:
	rm -rf *.o *.a *.so ../build/*
check:
	python3 cpplint.py --extensions=c,h  *
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
rebuild: clean all
