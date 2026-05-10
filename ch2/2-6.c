#include <stdio.h>
#include <limits.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    int shift = p + 1 - n;           // rightmost position
    unsigned low = (1U << n) - 1;    // n 1s at LSB(least significant bit)
    unsigned mask = low << shift;    // 1s at target
    return (x & ~mask) | ((y & low) << shift);
}

void print_binary(unsigned n) {
    int bits = sizeof(n) * CHAR_BIT;
    for (int i = bits - 1; i >= 0; i--) {
        putchar((n >> i) & 1 ? '1' : '0');
        if (i % 4 == 0 && i != 0) putchar('_'); // add _ to make more readable
    }
}

int main() {
    unsigned x = 0b10110011;
    unsigned y = 0b00000101;
    unsigned result = setbits(x, 5, 3, y);
    printf("%u\n", result);
    print_binary(result);
    return 0;
}