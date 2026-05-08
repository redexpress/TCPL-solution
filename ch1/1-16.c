#include <stdio.h>

#define MAXLINE 50

int my_getline (char line[ ], int maxline);
void copy ( char to[ ], char from [] );

int main(void) {
    int len;
    char line[ MAXLINE ];
    char longest[ MAXLINE ];
    int max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    printf("-------------------\n");
    if (max > 0) {
        printf("length: %d\n", max);
        printf("%s", longest);
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
    while (ch != EOF && ch != '\n') {
        ch = getchar();
        ++i;
    }
    return i;
}

void copy ( char to[ ], char from [] ) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}