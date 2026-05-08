#include <stdio.h>

int main() {
    int count_space = 0;
    int count_tab = 0;
    int count_newline = 0;
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            count_space++;
        } else if (ch == '\t') {
            count_tab++;
        } else if (ch == '\n') {
            count_newline++;
        }
    }
    printf("Spaces: %d Tabs: %d Newlines: %d\n",
        count_space, count_tab, count_newline);
}