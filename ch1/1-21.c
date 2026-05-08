#include <stdio.h>

#define TABSIZE 8

int main(void) {
    int c;
    int nblanks = 0;
    int ntab = 0;

    for (int pos = 1; (c = getchar()) != EOF; ++pos) {
        if (c == ' ') {
            if (pos % TABSIZE != 0) {
                ++nblanks;
            } else {
                // reached a tab stop, convert pending spaces to one tab
                nblanks = 0;
                ++ntab;
            }
        } else {
            for (int i = 0; i < ntab; ++i) {
                putchar('\t');
            }
            ntab = 0; // Reset tab count

            if (c == '\t') {
                // If the character is already a tab, pending spaces are redundant
                nblanks = 0;
            } else {
                // Flush pending spaces
                for (int i = 0; i < nblanks; ++i) {
                    putchar(' ');
                }
                nblanks = 0;
            }

            putchar(c);

            if (c == '\n') {
                pos = 0;
            } else if (c == '\t') {
                // Move pos to the last column of the current tab stop
                pos = pos + (TABSIZE - (pos - 1) % TABSIZE) - 1;
            }
        }
    }

    return 0;
}