CC=gcc

# -O0 no optimizations, -O3 all compiler optimizations
CFLAGS=-O3

%.o: %.c
	$(CC) $(CFLAGS) -c $^

main: main.c test.o bubbleSort.o insertionSort.o selectionSort.o
	$(CC) $(CFLAGS) -o main $^

clean:
	rm *.o main
