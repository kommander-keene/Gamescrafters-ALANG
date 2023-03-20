CC=gcc

CFLAGS = -g -O0

ODIR=obj

all: compiler

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

compiler: compiler.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f *.o core compiler
	rm -rf *.dSYM
