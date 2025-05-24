#include <stdio.h>
#include <stdint.h>


/*Function Converts Upper Case letter to lower */
uint8_t lower(uint8_t letter)
{
  return ((letter >='A' && letter <= 'Z') ? ((letter-'A') + 'a'):letter);
}


int32_t main(void)
{
    printf("%c\t", lower('A'));
    printf("%c\t", lower('B'));
    printf("%c\t", lower('k'));
    printf("%c\t", lower('Z'));
    printf("%c\t", lower('M'));
    printf("%c\t", lower('W'));
    printf("%c\t", lower('a'));


    return 0;
}