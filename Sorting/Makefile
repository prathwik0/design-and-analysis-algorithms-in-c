CC=gcc

# -O0 no optimizations, -O3 all compiler optimizations
# -g for debugging
# -I<folder_name> to include files in the <folder_name>

CFLAGS=-Iheader_files -O2

all: main

%.o: %.c
	$(CC) $(CFLAGS) -c $^

main: main.c test.o bubbleSort.o insertionSort.o selectionSort.o
	$(CC) $(CFLAGS) -o main $^
	rm *.o

clean:
	rm *.o main
