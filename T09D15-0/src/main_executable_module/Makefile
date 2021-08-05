TARGET = ../../build/Quest_3

.PHONY: all clean rebuild

all: $(TARGET)

$(TARGET): main.o io.o stat.o process.o decision.o
	gcc -o $(TARGET) main.o io.o stat.o process.o decision.o 

io.o: ../data_libs/data_io.c
	gcc -c ../data_libs/data_io.c -o io.o
stat.o: ../data_libs/data_stat.c
	gcc -c ../data_libs/data_stat.c -o stat.o
process.o: ../data_module/data_process.c
	gcc -c ../data_module/data_process.c -o process.o
decision.o: ../yet_another_decision_module/decision.c
	gcc -c ../yet_another_decision_module/decision.c -o decision.o
main.o: main_executable_module.c
	gcc -c main_executable_module.c -o main.o
io_macro.so: ../data_libs/data_io_macro.h
	gcc -c ../data_libs/data_io_macro.h -o io_macro.o
build_with_macro: io_macro.so main.o stat.o process.o decision.o
	gcc main.o stat.o process.o decision.o io_macro.o -o ../../build/Quest_4
data_stat.a: stat.o
	ar rc libdata_stat.a stat.o
	ranlib libdata_stat.a
build_with_static: main.o io.o data_stat.a process.o decision.o
	gcc -o ../../build/Quest_5 main.o io.o process.o decision.o -L. -ldata_stat
data_process.so: ../data_module/data_process.c stat.o
	gcc -fPIC -c ../data_module/data_process.c
	gcc -shared -o libdata_process.so data_process.o stat.o
build_with_dynamic: main.o io.o stat.o process.o decision.o data_process.so
	gcc main.o io.o process.o decision.o  -L. -ldata_process -o ../../build/Quest_6
clean:
	rm -rf *.o *.a *.so
rebuild:
	$(MAKE) clean
	$(MAKE) all