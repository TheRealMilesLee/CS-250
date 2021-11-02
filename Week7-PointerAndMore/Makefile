CC=clang
CFLAGS=-Wno-poison-system-directories -std=c89 -Weverything -pedantic-errors
OBJECTS=main.o file_handling.o add_contact.o delete_entry.o search_record.o count_total.o structure_contact.o

all: contacts

contacts: $(OBJECTS)
	$(CC) $(CFLAGS) -o contacts $(OBJECTS)

main.o: main.c 
	$(CC) $(CFLAGS) -Wno-padded -c main.c

file_handling.o: file_handling.c file_handling.h
		$(CC) $(CFLAGS) -Wno-padded -c file_handling.c file_handling.h

add_contact.o: add_contact.c add_contact.h
		$(CC) $(CFLAGS) -Wno-padded -c add_contact.c add_contact.h

delete_entry.o: delete_entry.c delete_entry.h
		$(CC) $(CFLAGS) -Wno-padded -c delete_entry.c delete_entry.h

search_record.o: search_record.c search_record.h
		$(CC) $(CFLAGS) -Wno-padded -c search_record.c search_record.h

count_total.o: count_total.c count_total.h
		$(CC) $(CFLAGS) -Wno-padded -c count_total.c count_total.h


structure_contact.o: structure_contact.c structure_contact.h
		$(CC) $(CFLAGS) -Wno-padded -c structure_contact.c structure_contact.h
clean:
	rm -f *.o *~ *.gch contacts
