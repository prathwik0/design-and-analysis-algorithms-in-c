#ifndef TEST_H
#define TEST_H

/*
 * Tests array of sorting functions
 * sort[] = array of sorting functions
 * sortFuncNames = array of the corresponding names of the sorting functions
 * numFunc = num of sorting functions provided
 *
 * nIter = number of iterations, say 10
 * min = min value of the unsorted array
 * max = max value of the unsorted array
 * count = array size to be tested for sorting
 */
void test(void (*sort[])(int *, int), const char *sortFuncNames[], int numFunc, int nIter, int min, int max, int count);

#endif