# Exercise2-3: Hexadecimal to Integer Conversion (`htoi`)

## Problem Statement

## Write a function `htoi(s)` that converts a string of hexadecimal digits (optionally starting with `0x` or `0X`) to its equivalent integer value.

## Build & Run

### Steps

1. **Compile**:
   ```bash
   gcc solution.c -o solution
   ```
2. **Execute**:
   ```bash
   ./solution
   ```

### Expected Output

```
0x1A -> 26
FF -> 255
0X3C -> 60
1z -> 1    (Stops at invalid character 'z')
```

---

## Input Format

The function `htoi` expects:

- A string containing:
  - Optional prefix `0x` or `0X`
  - Hexadecimal digits (`0-9`, `a-f`, or `A-F`)

**Valid Examples**:

- `"0x1A"`, `"ff"`, `"0X3C"`, `"123"`

**Invalid Handling**:

- Non-hex characters (e.g., `'g'`, `'z'`) will terminate conversion early.
- The prefix `0x`/`0X` is optional but must appear at the start if present.
