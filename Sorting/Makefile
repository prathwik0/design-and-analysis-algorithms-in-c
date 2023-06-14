CC=gcc

# -O0 no optimizations, -O3 all compiler optimizations
# -g for debugging
# -I<folder_name> to include all files in <folder_name>

CFLAGS=-Iheader_files -O2

all: main

%.o: %.c
	$(CC) $(CFLAGS) -c $^

main: main.c test.o bubbleSort.o selectionSort.o insertionSort.o mergeSort.o quickSort.o
	$(CC) $(CFLAGS) -o $@ $^
	rm *.o

clean:
	rm *.o main
