#include <stdio.h>
#include <stdbool.h>
// Use test.py to test this program
int main(void) {
    int ch;
    int nl = 0, nw = 0, nc = 0;
    bool in_word = false;

    while ((ch = getchar()) != EOF) {
        nc++;
        if (ch == '\n') {
            nl++;
        }

        if (ch == ' ' || ch == '\n' || ch == '\t') {
            in_word = false;
        } else if (!in_word) {
            in_word = true;
            nw++;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);
    return 0;
}