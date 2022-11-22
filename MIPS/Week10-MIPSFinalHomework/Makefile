CC=clang
CFLAGS=-Wno-poison-system-directories -std=c89 -Weverything -pedantic-errors
OBJECTS=MergeSort.o

all: MergeSort

MergeSort: $(OBJECTS)
	$(CC) $(CFLAGS) -o MergeSort $(OBJECTS)

MergeSort.o: MergeSort.c
	$(CC) $(CFLAGS) -Wno-padded -c MergeSort.c

clean:
	rm -f *.o *~ *.gch MergeSort
