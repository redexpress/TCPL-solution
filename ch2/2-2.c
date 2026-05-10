#include <stdio.h>

int main() {
    /*
    for ( i = 0; i < lim -1 &&(c = getchar()) != '\n' && c != EOF; ++i) {
        s[i] = c;
    }
    */
    int c;
    int lim = 100;
    char s[100];
    for (int i = 0; i < lim - 1; ++i) {
        c = getchar();
        if (c == '\n') break;
        if (c == EOF) break;
        s[i] = c;
    }
    return 0;
}