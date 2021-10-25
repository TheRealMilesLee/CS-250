CC=clang
CFLAGS=-Wno-poison-system-directories -std=c89 -Weverything -pedantic-errors
OBJECTS=Stok.o

all: stok

stok: $(OBJECTS)
	$(CC) $(CFLAGS) -o stok $(OBJECTS)

stok.o: Stok.c 
	$(CC) $(CFLAGS) -Wno-padded -c Stok.c
clean:
	rm -f *.o