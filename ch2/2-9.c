#include <stdio.h>

int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; b++)
        x &= x - 1;
    return b;
}

int main() {
    unsigned x = 0b10110011;
    int count = bitcount(x);
    printf("%d\n", count);
    return 0;
}