#include<stdio.h>
#include <stdint.h>
/* functions */


uint32_t rightrot(uint32_t value, uint8_t pos)
{
    uint8_t size=0;
    uint32_t bits =0;

    size = sizeof(value)*8;
    pos = pos % size;
    bits = value & (~(~0 << pos));

    return (value >> pos ) |(bits<<(size-pos));

}


int32_t main(void)
{
	uint32_t value = 0x5D78A72E;
	uint8_t pos;

    pos=1;

	printf("%x\n", rightrot(value, pos));  //0x2EBC5397
    pos=5;

	printf("%x\n", rightrot(value, pos));   //0x72EBC539

	return 0;
}