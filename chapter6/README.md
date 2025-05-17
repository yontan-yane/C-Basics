# Chapter 6: Structures

This chapter covers structures, which allow you to group related variables together under a single name.

## Topics Covered
- Basics of Structures
- Structures and Functions
- Arrays of Structures
- Pointers to Structures
- Self-referential Structures
- Table Lookup
- Typedef
- Unions
- Bit-fields

## Exercises
1. Our version of getword does not properly handle underscores, string constants, comments, or preprocessor control lines. Write a better version.
2. Write a program that reads a C program and prints in alphabetical order each group of variable names that are identical in the first 6 characters, but different somewhere thereafter. Don't count words within strings and comments.
3. Write a cross-referencer that prints a list of all words in a document, and, for each word, a list of the line numbers on which it occurs.
4. Write a program that prints the distinct words in its input sorted into decreasing order of frequency of occurrence. Precede each word by its count.
5. Modify the undcl program so that it does not add redundant parentheses to declarations.
6. Implement a simple version of the #define processor (i.e., no arguments) suitable for use with C programs, based on the routines of this section. You may also find getch and ungetch helpful.
7. Write a program that will print arbitrary input in a sensible way. As a minimum, it should print non-graphic characters in octal or hexadecimal according to local custom, and break long text lines.
8. Write a program to print a set of files, starting each new one on a new page, with a title and a running page count for each file.
9. Functions like isupper can be implemented to save space or to save time. Explore both possibilities.
10. Write a program to print a set of files, starting each new one on a new page, with a title and a running page count for each file. 