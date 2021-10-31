CC=clang
CFLAGS=-Wno-poison-system-directories -std=c89 -Weverything -pedantic-errors
OBJECTS=main.o delete_entry.o

all: contacts

contacts: $(OBJECTS)
	$(CC) $(CFLAGS) -o contacts $(OBJECTS)

main.o: main.c 
	$(CC) $(CFLAGS) -Wno-padded -c main.c

delete_entry.o: delete_entry.c delete_entry.h
		$(CC) $(CFLAGS) -Wno-padded -c delete_entry.c delete_entry.h

clean:
	rm -f *.o *~ *.gch contacts
