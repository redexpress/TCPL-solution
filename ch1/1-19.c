#include <stdio.h>

#define MAXLINE 50

int my_getline (char line[], int maxline);
void reverse(char s[]);

int main(void) {
    int len;
    char line[MAXLINE];
    int max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

int my_getline (char line[ ], int maxline) {
    int ch;
    int i;
    for ( i = 0; i < maxline -1 && (ch = getchar()) != EOF && ch != '\n'; ++i ) {
        line[i] = ch;
    }
    if (ch == '\n') {
        line[i] = ch;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void reverse(char s[]) {
    if (!s || !*s) return;

    char *end = s;
    while (end[1] && end[1] != '\n') end++;

    while (s < end) {
        char t = *s;
        *s = *end;
        *end = t;

        s++;
        end--;
    }
}