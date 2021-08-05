FLAGS = -Wall -Wextra -Werror=format-security
.PHONY: all clean rebuild
 
all: text_processor strtok_tests strlen_tests strstr_tests strchr_tests strcat_tests strcpy_tests strcmp_tests strlen_tests
text_processor: s21_string.o processor.o
	gcc $(FLAGS) s21_string.o processor.o -o ../build/Quest_8
strtok_tests: s21_string.o s21_string_test.o
	gcc -D Quest_7 -c main.c -o main.o
	gcc s21_string.o s21_string_test.o main.o -o ../build/Quest_7
strstr_tests: s21_string.o s21_string_test.o
	gcc -D Quest_6 -c main.c -o main.o
	gcc s21_string.o s21_string_test.o main.o -o ../build/Quest_6
strchr_tests: s21_string.o s21_string_test.o
	gcc -D Quest_5 -c main.c -o main.o
	gcc s21_string.o s21_string_test.o main.o -o ../build/Quest_5
strcat_tests: s21_string.o s21_string_test.o
	gcc -D Quest_4 -c main.c -o main.o
	gcc s21_string.o s21_string_test.o main.o -o ../build/Quest_4
strcpy_tests: s21_string.o s21_string_test.o
	gcc -D Quest_3 -c main.c -o main.o
	gcc s21_string.o s21_string_test.o main.o -o ../build/Quest_3
strcmp_tests: s21_string.o s21_string_test.o
	gcc -D Quest_2 -c main.c -o main.o
	gcc s21_string.o s21_string_test.o main.o -o ../build/Quest_2
strlen_tests: s21_string.o s21_string_test.o
	gcc -D Quest_1 -c main.c -o main.o
	gcc s21_string.o s21_string_test.o main.o -o ../build/Quest_1
s21_string.o: s21_string.c
	gcc -c s21_string.c -o s21_string.o
s21_string_test.o: s21_string_test.c
	gcc -c s21_string_test.c -o s21_string_test.o
processor.o: text_processor.c
	gcc -c text_processor.c -o processor.o
main.o: main.c
	gcc -c main.c -o main.o
clean:
	rm -rf *.o *.a *.so ../build/*
rebuild:
	$(MAKE) clean
	$(MAKE) all