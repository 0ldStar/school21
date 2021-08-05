.PHONY: all clean rebuild
FLAGS =-Wall -Werror -Wextra

all: state_sort state_search clear_state
state_sort: state_sort.c fileArrWork.c fileIO.c sort.c
	gcc $(FLAGS) state_sort.c fileArrWork.c fileIO.c sort.c -o ../build/Quest_1
state_search: state_search.c fileArrWork.c fileIO.c sort.c
	gcc $(FLAGS) state_search.c fileArrWork.c fileIO.c sort.c -o ../build/Quest_2
clear_state: clear_state.c fileArrWork.c fileIO.c sort.c
	gcc $(FLAGS) clear_state.c fileArrWork.c fileIO.c sort.c -o ../build/Quest_3
clean:
	rm -rf *.o *.a *.so ../build/*
check:
	python3 cpplint.py --extensions=c,h  *
	leaks --atExit -- ../build/Quest_3
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
rebuild: clean all
