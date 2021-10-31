CC=clang
CFLAGS=-Wno-poison-system-directories -std=c89 -Weverything -pedantic-errors
OBJECTS=main.o file_handling.o add_entry.o delete_entry.o search_record.o

all: contacts

contacts: $(OBJECTS)
	$(CC) $(CFLAGS) -o contacts $(OBJECTS)

main.o: main.c 
	$(CC) $(CFLAGS) -Wno-padded -c main.c

file_handling.o: file_handling.c file_handling.h
		$(CC) $(CFLAGS) -Wno-padded -c file_handling.c file_handling.h

add_entry.o: add_entry.c add_entry.h
		$(CC) $(CFLAGS) -Wno-padded -c add_entry.c add_entry.h

delete_entry.o: delete_entry.c delete_entry.h
		$(CC) $(CFLAGS) -Wno-padded -c delete_entry.c delete_entry.h

search_record.o: search_record.c search_record.h
		$(CC) $(CFLAGS) -Wno-padded -c search_record.c search_record.h
clean:
	rm -f *.o *~ *.gch contacts
