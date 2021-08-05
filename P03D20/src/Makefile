.PHONY: all clean rebuild
 FLAGS -Wall -Werror=format-security -Wextra

all: plot stack polka parcer main
	gcc $(FLAGS) main.o plot.o stack.o polka.o parcer.o -o../build/graph
main: graph.c
	gcc $(FLAGS) -c graph.c -o main.o
plot: plot.c
	gcc $(FLAGS) -c plot.c -o plot.o
stack: stack.c
	gcc $(FLAGS) -c stack.c -o stack.o
polka: polka.c
	gcc $(FLAGS) -c polka.c -o polka.o
parcer: parcer.c
	gcc $(FLAGS) -c parcer.c -o parcer.o
clean:
	rm -rf *.o *.a *.so ../build/*
rebuild:
	$(MAKE) clean
	$(MAKE) all