# Exercise 4-6

Add commands for handling variables. (It's easy to provide twenty six variables with single-letter names.) Add a variable for the most recently printed value.

## Description
This program extends the reverse Polish notation calculator from the book, first introduced in exercise 4-3.

We can assign values to the variables 'A'-'Z' via a command of the form:
```bash
3 A =
```
 
We can also access to the most recently printed value with the '$' variable:
```bash
$ 3 +
```

## Compilation

To compile, use:
```bash
gcc solution.c -o solution
```

## Running

After compilation, run the program:
```bash
./solution
```
