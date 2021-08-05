.PHONY: all clean rebuild
 
all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test
print_module: print_module.c main_module_entry_point.c
	gcc -Wall -Werror=format-security print_module.c main_module_entry_point.c -o ../build/Quest_1
documentation_module: documentation_module.c 
	gcc -D DOC -Wall -Werror=format-security -Wextra documentation_module.c main_module_entry_point.c print_module.c -o ../build/Quest_2
bst_create_test: bst_create_test.c bst.o
	gcc -Wall -Werror=format-security -Wextra bst_create_test.c bst.o -o ../build/Quest_3
bst_insert_test: bst_insert_test.c bst.o
	gcc -Wall -Werror=format-security -Wextra bst_insert_test.c bst.o -o ../build/Quest_4
bst_traverse_test: bst_traverse_test.c bst.o
	gcc -Wall -Werror=format-security -Wextra bst_traverse_test.c bst.o -o ../build/Quest_5
bst.o: bst.c
	gcc -c bst.c -o bst.o
clean:
	rm -rf *.o *.a *.so ../build/*
rebuild:
	$(MAKE) clean
	$(MAKE) all