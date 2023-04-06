CFLAGS = -I. -I./inc

TARGET = AS1_run
OBJECTS = main.o matrix.o


$(TARGET): $(OBJECTS)
	gcc -o main_run $(OBJECTS)

main.o: main.c 
	gcc -c main.c -I./inc

matrix.o: matrix.c
	gcc -c matrix.c -I./inc
	 
clean:
	rm -r *.o

