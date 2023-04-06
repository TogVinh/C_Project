CFLAGS = -I. -I./inc

TARGET = as2_p1_run
OBJECTS = main.o array.o

$(TARGET): $(OBJECTS)
	gcc -o $(TARGET) $(OBJECTS)

main.o: main.c 
	gcc -c main.c -I./inc

array.o: array.c
	gcc -c array.c -I./inc
	 
clean:
	rm -r *.o
