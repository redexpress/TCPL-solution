#include <stdio.h>

#define TABSIZE 8

int main() {
    int ch;
    int nblanks;
    int pos = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == '\t') {
            nblanks = TABSIZE - (pos % TABSIZE);
            while (nblanks > 0) {
                putchar(' ');
                ++pos;
                --nblanks;
            }
        } else if (ch == '\n') {
            putchar(ch);
            pos = 0;
        } else {
            putchar(ch);
            ++pos;
        }
    }
    return 0;
}