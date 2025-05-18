#include <stdio.h>

int main()
{
    printf("hello, world\n");    /* \n is valid */
    printf("hello, world\\c is invalid\n");    /* \c is invalid */
    printf("hello, world\\7 is valid\n");    /* \7 is valid (bell) */
    printf("hello, world\\? is valid\n");    /* \? is valid */
    printf("hello, world\\x is invalid\n");    /* \x is invalid */
} 
