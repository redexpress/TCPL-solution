#include <stdio.h>
#include <stdbool.h>

int main() {
    int len = 0;
    int longest = 0;
    enum { MAX_LEN = 128 };
    int counts[MAX_LEN + 1] = {0};
    bool in_word = false;

    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch >= ' ' || ch <= '~') {
            counts[ch]++;
        }
    }

    printf("horizontal histogram\n");
    for (int i = ' '; i <= '~'; i++) {
        if (counts[i] == 0) {
            continue;
        }
        printf("%c | ", i);
        for (int j = 0; j < counts[i]; j++) {
            putchar('#');
        }
        putchar('\n');
    }

    return 0;
}