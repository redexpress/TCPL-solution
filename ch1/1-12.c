#include <stdio.h>
#include <stdbool.h>

int main() {
    int ch;
    bool in_word = false;

    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (in_word) {
                putchar('\n');
                in_word = false;
            }
        } else {
            in_word = true;
            putchar(ch);
        }
    }

    return 0;
}