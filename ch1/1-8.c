#include <stdio.h>

int main() {
    int nspaces = 0;
    int ntabs = 0;
    int nnewlines = 0;
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            nspaces++;
        } else if (ch == '\t') {
            ntabs++;
        } else if (ch == '\n') {
            nnewlines++;
        }
    }
    printf("Spaces: %d Tabs: %d Newlines: %d\n",
        nspaces, ntabs, nnewlines);
}