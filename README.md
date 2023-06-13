# Design and Analysis of Algorithms (DAA) in C

## List of programs

| No. |        Title         | Algorithms                                               |            Time Complexity             | Space Complexity |
|:---:|:--------------------:|:---------------------------------------------------------|:--------------------------------------:|:----------------:|
|  1  |         GCD          | [Euclid's algorithm](GCD/euclidsAlgorithm.c)             |         O($`log(\min(a,b))`$)          |      O($1$)      |
|     |                      | [Consecutive Integer](GCD/consecutiveInteger.c)          |            O($`\min(a,b)`$)            |      O($1$)      |
|     |                      | [Middle School Method](GCD/combined.c)                   |                 O($n$)                 | O($maxFactors$)  |
|  2  |    Prime Numbers     | [Sieve of Eratosthenes](PrimeNumbers/sieve.c)            |            O($n\log\log n$)            |      O($n$)      |
|  3  |      Factorial       | [Iterative Version](Fibonacci/iteration.c)               |                                        |                  |
|     |                      | [Recursive Version](Fibonacci/recursion.c)               |                O($n!$)                 |                  |
|  4  |      Fibonacci       | [Iterative Version](Factorial/iteration.c)               |                                        |                  |
|     |                      | [Recursive Version](Factorial/recursion.c)               |                O($2^n$)                |                  |
|  5  |    Tower of Hanoi    | [Tower of Hanoi](TowerOfHanoi/toh.c)                     |                O($2^n$)                |      O($n$)      |
|  6  |       Matrices       | [Matrix Multiplication](Matrices/matrixMultiplication.c) |                O($n^3$)                |     O($n^2$)     |
|  7  | Searching Algorithms | [Linear Search](Search/linearSearch.c)                   |      $\Omega(1)\ \Theta(n)\ O(n)$      |                  |
|     |                      | [Binary Search](Search/binarySearch.c)                   | $\Omega(1)\ \Theta(\log n)\ O(\log n)$ |                  |
|  8  |  Sorting Algorithms  | [Bubble Sort](Sorting/bubbleSort.c)                      |    $\Omega(n)\ \Theta(n^2)\ O(n^2)$    |      $O(1)$      |
|     |                      | [Selection Sort](Sorting/selectionSort.c)                |   $\Omega(n^2)\ \Theta(n^2)\ O(n^2)$   |      $O(1)$      |
|     |                      | [Insertion Sort](Sorting/insertionSort.c)                |    $\Omega(n)\ \Theta(n^2)\ O(n^2)$    |      $O(1)$      |
