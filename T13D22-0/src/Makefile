.PHONY: all clean rebuild
 FLAGS -Wall -Werror=format-security -Wextra

all: cipher loggin_cipher
cipher: cipher.c
	gcc $(FLAGS) cipher.c -o ../build/cipher
loggin_cipher:
	gcc -D LOG $(FLAGS) cipher.c logger.c -o ../build/logging_cipher
clean:
	rm -rf *.o *.a *.so ../build/*
check:
	python3 cpplint.py --extensions=c,h  *
	cppcheck --enable=all --suppress=missingIncludeSystem *.c -D LOG
rebuild:
	$(MAKE) clean
	$(MAKE) all