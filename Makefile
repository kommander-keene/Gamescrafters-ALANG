CC = gcc
CFLAGS = -Wall -Wextra -g -w
LIBS = -lm

# List your dependencies here
DEPS = general.h test.h 
INSIDE = -I./parser -I./ -I./reader -I./lexer
CES = types/61b.c reader/reader.c lexer/lexer.c

all: test

# Define the test target and its dependencies
main: $(CES) main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
main.o: main.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
test: $(CES) test.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

test.o: test.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

# Add the files defined by CES as dependencies to the test target
$(CES): $(DEPS)

clean:
	rm -f *.o test
