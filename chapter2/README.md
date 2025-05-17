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
1. Determine ranges of char, short, int, and long variables
2. Write a loop equivalent to the for loop without using && or ||
3. Write a function htoi(s) that converts a string of hexadecimal digits into its equivalent integer value
4. Write an alternate version of squeeze(s1,s2) that deletes each character in s1 that matches any character in s2
5. Write the function any(s1,s2), which returns the first location in a string s1 where any character from s2 occurs, or -1 if s1 contains no characters from s2
6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y
7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted
8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions
9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount
10. Rewrite the function lower, which converts upper case letters to lower case, using a conditional expression instead of if-else 