#include <stdio.h>

int main(void) {
    int c;
    int result = ((c = getchar()) != EOF);
    printf("result: %d, c: %d\n", result, c); // result: 1, c: 99
}