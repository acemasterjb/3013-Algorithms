# Program 1 - Complex Vector from Scratch

This program simulates the operations of a complex implementation of a vector.

The [`Vector`](./Vector.h) class uses a [`LinkedList`](./containers/LinkedList.h) as its container.

This `Vector` class was written to support pushing and popping from both ends and initialization from arrays, input files and other Vectors.

This `Vector` class also supports "pushing in order" which means that elements can be pushed and then sorted.

The [`solution.cpp`](./solution.cpp) file contains logic to test the various operations of this `Vector` class.

Input files need to consist of lines where each line contains one element to be pushed onto the Vector. E.g. for initializing a `Vector` of `int`s each line in the input file needs to be an integer.

## Instructions

1. Compile the `solution.cpp` source file ([Unix and Windows Tutorial](https://www.codecademy.com/article/cpp-compile-execute-locally), or run [`solution.cpp`](./solution.cpp) in [replit](https://replit.com/)).
2. Run the compiled `solution` program.

e.g.

```text
# contents of input

12
14
200
```

```console
# terminal/cmd

$ ./solution
# ...
```

That is, after compiling `solution.cpp` you should get a `solution` executable file in the same directory `solution.cpp` is stored. You can then run this command `./solution` to output the various `Vector` tests contained in `solution.cpp`.

## Sorting Algorithm

Merge sort was selected as the sorting algorithm based on some research on what may be the best sorting algorithm for sorting an array.

The recursive algorithm simply partitions a given linked list into two and splits those partitions until one node is left in the partition.

Then the merging step merges the two last partitions on the runtime stake. Based on the definition of this algorithm, this merged sublist is sorted.

Therefore the sublists from the runtime stack are always sorted. When all recursive calls to the merge sort algorithm are resolved the inputted linked list is guaranteed to be sorted.

GPT-4 was consulted for a solution to partitioning linked lists.
