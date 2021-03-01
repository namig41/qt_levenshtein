# qt_levenshtein

Based on Wagner-Fischer dynamic programming algorithm, optimized for speed and memory
 - use a single distance vector instead of a matrix
 - loop unrolling on the outer loop
 - remove common prefixes/postfixes from the calculation
 - minimize the number of comparisons
 - always allocate a new distance vector in order to not leak memory

## Build and run

```
sudo apt-get install qt5-default
qmake && make 
./lab4
```
