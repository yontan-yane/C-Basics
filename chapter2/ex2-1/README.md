# Exercise 2-1

**Print ranges of C data types using headers and bitwise computation**

## Description

This program prints the minimum and maximum values of C's `char`, `short`, `int`, `long`, and `long long` types (both signed and unsigned). It uses two methods:

1. **Standard Headers**: Values from `<limits.h>` (e.g., `INT_MAX`).
2. **Direct Computation**: Bitwise operations to calculate ranges manually.

---

## Usage

1. **Compile**:
   ```bash
   gcc solution.c -o solution
   ```
2. **RUN**

   ```bash
   ./solution
   ```

## Expected Output

```bash
Ranges from <limits.h>
signed char:            -128 to 127
unsigned char:          0 to 255
signed short:           -32768 to 32767
unsigned short:         0 to 65535
signed int:             -2147483648 to 2147483647
unsigned int:           0 to 4294967295
signed long:            -9223372036854775808 to 9223372036854775807
unsigned long:          0 to 18446744073709551615
signed long long:       -9223372036854775808 to 9223372036854775807
Unsigned long long:     0 to 18446744073709551615

Computed Ranges
signed char:            -128 to 127
unsigned char:          0 to 255
...
```
