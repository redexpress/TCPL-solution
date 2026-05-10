#include <stdio.h>
#include <limits.h>

unsigned rightrot(unsigned x, int p, int n) {
    int bits = sizeof(x) * CHAR_BIT;   // number of bits in unsigned
    n = n % bits;                      // handle n larger than bit width
    if (n == 0) return x;
    return (x >> n) | (x << (bits - n));// xor flips only the mask bits
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
    unsigned result = rightrot(x, 0, 3);
    printf("%u\n", result);
    printf("     x: ");
    print_binary(x);
    printf("\nx>>3 x: ");
    print_binary(result);
    return 0;
}