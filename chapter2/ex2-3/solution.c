#include <stdio.h>
#include <stdint.h>

int32_t htoi(uint8_t *str)
{
    int32_t temp=0, index_i, result=0;
    index_i=0;

    if((str[index_i]=='0') && \
            (str[index_i+1] == 'x' || str[index_i+1] == 'X'))
    {
        index_i+=2;
    }
    while(str[index_i] != 0) //until  '\0'
    {

        if(str[index_i] >='0' && str[index_i] <= '9')
        {

            temp = (str[index_i]-'0');
            
        }
        else if((str[index_i] >='A' && str[index_i]<='F') || 
        ((str[index_i] >='a') && (str[index_i]<='f') ))
        {
            temp = ((str[index_i]-'A') & (~('A' ^ 'a')))+10;

        }
        else
        {
           break;
        }

        result = result *16 + temp; //for hex: 16, 
        index_i++;
    }
    return result;
}


int main(void) {
    printf("%d\n", htoi("0x1A"));  // Output: 26
    printf("%d\n", htoi("FF"));     // Output: 255
    printf("%d\n", htoi("0X3C"));   // Output: 60
    printf("%d\n", htoi("1A"));     // Output: 26
    printf("%d\n", htoi("A"));      // Output: 10
    printf("%d\n", htoi("0x80000000"));      // Output: -2147483648
    return 0;
}



