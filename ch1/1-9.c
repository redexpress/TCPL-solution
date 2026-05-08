#include <stdio.h>
#include <stdbool.h>

int main() {
    int ch;
    bool was_space = false;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            if (!was_space) {
                putchar(ch);
                was_space = true;
            }
        } else {
            putchar(ch);
        }
    }
}