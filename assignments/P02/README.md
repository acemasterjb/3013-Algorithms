# Program 2 - Json Linear Search

This program grabs words from a dictionary `.json` file and uses it to predict the text a user types in their console.
It utilizes [N_Lohmann's](https://github.com/nlohmann/json) json library](https://github.com/nlohmann/json) to deserialize the json file into a data structure that then gets its keys extracted. These keys make up the dictionary's entries.

When a user types text in the console this program creates a subset of the loaded dictionary and prints out the top 10 entries from the dictionary as well as the total number of results found.

Other statistics are shown, including the loading time of the dictionary and the time to find the predicted text results.

## Instructions

1. Compile the `main.cpp` source file ([Unix and Windows Tutorial](https://www.codecademy.com/article/cpp-compile-execute-locally), or run [`main.cpp`](./main.cpp) in [replit](https://replit.com/)).
2. Run the compiled `main` program.

e.g.

```console
# terminal/cmd

$ ./main
GETCH WORD LOOKUP

Load Time for data file:
1  seconds

1853  milliSeconds

1853433369  nanoSeconds

Type a word to begin...
```

That is, after compiling `main.cpp` you should get a `main` executable file in the same directory `main.cpp` is stored.

You can then run this command `./main` to run the predicted text program contained in `main.cpp`.
