# Chapter 5: Pointers and Arrays

This chapter covers pointers and arrays, which are fundamental to C programming and provide powerful ways to manipulate data.

## Topics Covered
- Pointers and Addresses
- Pointers and Function Arguments
- Pointers and Arrays
- Address Arithmetic
- Character Pointers and Functions
- Pointer Arrays; Pointers to Pointers
- Multi-dimensional Arrays
- Initialization of Pointer Arrays
- Pointers vs. Multi-dimensional Arrays
- Command-line Arguments
- Pointers to Functions
- Complicated Declarations

## Exercises
1. Write a function getint that gets the next integer from input into a variable provided by the caller.
2. Write a function getfloat, analogous to getint, that gets the next floating-point number from input into a variable provided by the caller.
3. Write a pointer version of the function strcat that we showed in Chapter 2.
4. Write the function strend(s, t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise.
5. Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings.
6. Write a program that reads a set of lines, sorts them, and prints them in increasing order.
7. Modify the sort program to handle a -n flag, which indicates that comparisons should be made numerically rather than lexicographically.
8. Add the -r flag, which indicates sorting in reverse (decreasing) order, to the sort program.
9. Add the capability to sort on arbitrary fields within lines, rather than the whole line, to the sort program.
10. Write a program to print a set of files, starting each new one on a new page, with a title and a running page count for each file 