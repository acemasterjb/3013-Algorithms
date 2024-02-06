# Program 1 - Complex Vector from Scratch

This program simulates the operations of a complex implementation of a vector.

The [`Vector`](./Vector.h) class uses a [`LinkedList`](./containers/LinkedList.h) as its container.

This `Vector` class was written to support pushing and popping from both ends and initialization from arrays, input files and other Vectors.

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
