CC=clang
CFLAGS=-Wno-poison-system-directories -std=c89 -Weverything -pedantic-errors
OBJECTS=main.o revbits.o atoh.o

all: revbits

revbits: $(OBJECTS)
	$(CC) $(CFLAGS) -o revbits $(OBJECTS)

main.o: main.c atoh.h revbits.h
	$(CC) $(CFLAGS) -Wno-padded -c main.c

atoh.o: atoh.h atoh.c
	$(CC) $(CFLAGS) -c atoh.c

revbits.o: revbits.c revbits.h atoh.h
	$(CC) $(CFLAGS) -Wno-padded -c revbits.c

clean:
	rm -f *.o revbits
