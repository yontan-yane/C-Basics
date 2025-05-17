# Chapter 2: Types, Operators, and Expressions

This chapter covers the basic building blocks of C programs: variables, constants, data types, and operators.

## Topics Covered
- Variable Names
- Data Types and Sizes
- Constants
- Declarations
- Arithmetic Operators
- Relational and Logical Operators
- Type Conversions
- Increment and Decrement Operators
- Bitwise Operators
- Assignment Operators and Expressions
- Conditional Expressions
- Precedence and Order of Evaluation

## Exercises
1. Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation.
2. Write a loop equivalent to the for loop without using && or ||.
3. Write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value.
4. Write an alternate version of squeeze(s1, s2) that deletes each character in s1 that matches any character in the string s2.
5. Write the function any(s1, s2), which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
6. Write a function setbits(x, p, n, y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
7. Write a function invert(x, p, n) that returns x with the n bits that begin at position p inverted, leaving the others unchanged.
8. Write a function rightrot(x, n) that returns the value of the integer x rotated to the right by n bit positions.
9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount.
10. Rewrite the function lower, which converts upper case letters to lower case, using a conditional expression instead of if-else. 