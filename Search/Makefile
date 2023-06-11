CC=gcc

# -O0 no optimizations, -O3 all compiler optimizations
CFLAGS= -g -O2

all: linearSearch binarySearch binarySearchRecursive

%.o: %.c
	$(CC) $(CFLAGS) -c $^

linearSearch: test.o linearSearch.c
	$(CC) $(CFLAGS) $^ -o $@

binarySearch: test.o binarySearch.c
	$(CC) $(CFLAGS) $^ -o $@

binarySearchRecursive: test.o binarySearchRecursive.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm *.o linearSearch binarySearch binarySearchRecursive
