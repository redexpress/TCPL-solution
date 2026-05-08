#include <stdio.h>
#include <stdbool.h>

int main() {
    int len = 0;
    int longest = 0;
    enum { MAX_LEN = 100 };
    int counts[MAX_LEN + 1] = {0};
    bool in_word = false;

    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (in_word) {
                if (len <= MAX_LEN) counts[len]++;
                len = 0;
                in_word = false;
            }
        } else {
            in_word = true;
            len++;
        }
        if (len > longest) {
            longest = len;
        }
    }

    printf("horizontal histogram\n");
    for (int i = 1; i <= longest; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < counts[i]; j++) {
            putchar('#');
        }
        putchar('\n');
    }

    return 0;
}