CC=gcc
CFLAGS=-Wall -g -O -I. -MMD
LFLAGS=
PROGS=EX
all: $(PROGS)
EX: EX.o $(OBJECTS)
$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

-include *.d

clean:
/bin/rm -f $(PROGS) *.o a.out

