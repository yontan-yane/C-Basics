# Chapter 4: Functions and Program Structure

This chapter covers functions, program structure, and the organization of C programs into multiple files.

## Topics Covered
- Basics of Functions
- Functions Returning Non-integers
- External Variables
- Scope Rules
- Header Files
- Static Variables
- Register Variables
- Block Structure
- Initialization
- Recursion
- The C Preprocessor

## Exercises
1. Write the function strrindex(s, t), which returns the position of the rightmost occurrence of t in s, or -1 if there is none.
2. Extend atof to handle scientific notation of the form 123.45e-6.
3. Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers.
4. Add commands to print the top element of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.
5. Add access to library functions like sin, exp, and pow. See <math.h> in Appendix B, Section 4.
6. Add commands for handling variables. (It's easy to provide twenty-six variables with single-letter names.)
7. Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about a buffer, or should it use ungetch?
8. Suppose that there will never be more than one character of pushback. Modify getch and ungetch accordingly.
9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought to be if an EOF is pushed back, then implement your design.
10. An alternate organization uses getline to read an entire input line; this makes getch and ungetch unnecessary. Revise the calculator to use this approach 