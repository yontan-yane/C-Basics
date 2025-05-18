#include <stdio.h>
#include <limits.h>

int main() {
    // Print ranges from standard headers
    printf("Ranges from <limits.h>\n");
    printf("signed char:            %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char:          0 to %u\n", UCHAR_MAX);
    printf("signed short:           %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short:         0 to %u\n", USHRT_MAX);
    printf("signed int:             %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int:           0 to %u\n", UINT_MAX);
    printf("signed long:            %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long:          0 to %lu\n", ULONG_MAX);
    printf("signed long long:       %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("Unsigned long long:     0 to %llu\n\n", ULLONG_MAX);

    // Compute ranges directly
    printf("Computed Ranges\n");
    
    // Signed char
    unsigned char uc_max = (unsigned char)-1;
    signed char c_max = (signed char)(uc_max >> 1);
    printf("signed char:            %d to %d\n", -((int)c_max + 1), c_max);
    
    // Unsigned char
    printf("unsigned char:          0 to %u\n", uc_max);
    
    // Signed short
    unsigned short us_max = (unsigned short)-1;
    signed short s_max = (signed short)(us_max >> 1);
    printf("signed short:           %d to %d\n", -((int)s_max + 1), s_max);
    
    // Unsigned short
    printf("unsigned short:         0 to %u\n", us_max);
    
    // Signed int
    unsigned int ui_max = (unsigned int)-1;
    signed int i_max = (signed int)(ui_max >> 1);
    printf("signed int:             %d to %d\n", -((int)i_max + 1), i_max);
    
    // Unsigned int
    printf("unsigned int:           0 to %u\n", ui_max);
    
    // Signed long
    unsigned long ul_max = (unsigned long)-1;
    signed long l_max = (signed long)(ul_max >> 1);
    printf("signed long:            %ld to %ld\n", -((long)l_max + 1), l_max);
    
    // Unsigned long
    printf("unsigned long:          0 to %lu\n", ul_max);

    // Signed long long
    unsigned long long ull_max = (unsigned long long)-1;
    signed long long ll_max = (signed long long)(ull_max >> 1);
    printf("signed long long:       %lld to %lld\n", -((long long)ll_max + 1), ll_max);
    
    // Unsigned long long
    printf("unsigned long long:     0 to %llu\n", ull_max);

    return 0;
}