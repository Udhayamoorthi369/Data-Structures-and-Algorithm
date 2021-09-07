CC=gcc
CFLAGS=-Wall
EXECUTABLE=list
list: sorted_linked_list.o main.c
	$(CC) $(CFLAGS) sorted_linked_list.o main.c -o $(EXECUTABLE)
sorted_linked_list.o: sorted_linked_list.h 
clean:
	rm -rf *.o *.gch $(EXECUTABLE)

