#include <stdio.h>
#include <limits.h>

/*
Use XOR (^) operation:
0 ^ 1 = 1 (flip 0 to 1)
1 ^ 1 = 0 (flip 1 to 0)
x ^ 0 = x (unchanged)

So construct a mask that has 1s at the bits to flip,
and 0 elsewhere, then return x ^ mask.
 */
unsigned invert(unsigned x, int p, int n) {
    int shift = p + 1 - n;               // position of the lowest bit in the group
    unsigned low = (1U << n) - 1;        // n ones at the low end
    unsigned mask = low << shift;        // move those ones to the target bits
    return x ^ mask;                     // xor flips only the mask bits
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
    unsigned result = invert(x, 5, 3);
    printf("%u\n", result);
    printf("       x: ");
    print_binary(x);
    printf("\ninvert x: ");
    print_binary(result);
    return 0;
}