# run the sequential solution

> 1. gcc -o sequencial sequencial.c
> 2. ./sequencial < sequential_test_file

# run the paralel solution

> 1. gcc -pthread -o paralel paralel.c
> 2. ./paralel < paralel_test_file

### structure of the sequential test file

The first line contains an integer, `n`, denoting the size of the array. The next line contains `n` space-separated integers denoting the elements of the array.

### structure of the paralel test file
The first line contains an integer, `t`, denoting the number of threads to be created/exeecuted. The second line contains an integer, `n`, denoting the size of the array. The third line contains `n` space-separated integers denoting the elements of the array.
