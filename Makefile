CC=gcc
CFLAGS=-Wall
EXECUTABLE=list
list: sorted_linked_list.o main.c
	$(CC) $(CFLAGS) sorted_linked_list.o main.c -o $(EXECUTABLE)
linkedlist.o: linkedlist.h 
clean:
	rm -rf *.o *.gch $(EXECUTABLE)

