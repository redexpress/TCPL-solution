#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define THRESHOLD 80

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void) {
    int len, nlines = 0;
    char line[MAXLINE];
    char **lines = NULL;
    const int LINE_SIZE = 5;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (len - 1 > LINE_SIZE) {
            char **temp = (char **)realloc(lines, (nlines + 1) * sizeof(char *));
            if (temp == NULL) return 1;
            lines[nlines] = (char *)malloc(len);
            copy(lines[nlines], line);
            nlines++;
        }
    }

    printf("-------------------\n");
    for (int i = 0; i < nlines; i++) {
        printf("%s", lines[i]);
        free(lines[i]);
    }
    free(lines);
    return 0;
}

int my_getline(char line[], int maxline) {
    int ch, i = 0;
    while (i < maxline - 1 && (ch = getchar()) != EOF && ch != '\n') {
        line[i++] = ch;
    }
    if (ch == '\n') {
        line[i++] = '\n';
    }
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
