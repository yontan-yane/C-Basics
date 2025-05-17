# Chapter 8: The UNIX System Interface

This chapter covers the UNIX system interface, including file operations, process control, and memory management.

## Topics Covered
- File Descriptors
- Low Level I/O - read and write
- Open, creat, close, unlink
- Random Access - lseek
- Example - An implementation of Fopen and getc
- Example - Listing Directories
- Example - A Storage Allocator

## Exercises
1. Rewrite the program cat from Chapter 7 using read, write, open, and close instead of their standard library equivalents. Perform experiments to determine the relative speeds of the two versions.
2. Write a program that, given a directory, prints the names of all files in that directory, one per line.
3. Write a program to compare two files, printing the first line where they differ.
4. Write a program to print all lines that are longer than 80 characters.
5. Modify the fsize program to print the other information contained in the inode entry.
6. Write a program to print a directory tree, showing all files and subdirectories.
7. Modify the pattern-finding program of Chapter 5 to take its input from a set of named files or, if no files are named as arguments, from the standard input. Should the file name be printed when a matching line is found?
8. Write a program to print the last 10 lines of a file (like the UNIX tail command).
9. Write a program to print the longest input line.
10. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. 