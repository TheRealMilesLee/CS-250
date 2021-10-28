CC=clang
CFLAGS=-Wno-poison-system-directories -std=c89 -Weverything -pedantic-errors
OBJECTS=main.o file_handling.o

all: contacts

contacts: $(OBJECTS)
	$(CC) $(CFLAGS) -o contacts $(OBJECTS)

main.o: main.c 
	$(CC) $(CFLAGS) -Wno-padded -c main.c

file_handling.o: file_handling.c file_handling.h
	$(CC) $(CFLAGS) -Wno-padded -c file_handling.c file_handling.h
	
clean:
	rm -f *.o *~ *.gch contacts
