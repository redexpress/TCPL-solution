#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

int my_getline (char line[ ], int maxline);
void copy ( char to[ ], char from [] );

int main(void) {
    int nlines = 0;
    char line[MAXLINE];
    char **lines = NULL;
    int len;

    while ((len = my_getline(line, MAXLINE)) > 0) {
        //
        int i = len - 1;
        while (i >= 0 && (line[i] == '\n' || line[i] == ' ' || line[i] == '\t')) {
            i--;
        }

        if (i >= 0) {
            line[i + 1] = '\0';

            char **temp = (char **)realloc(lines, (nlines + 1) * sizeof(char *));
            if (temp == NULL) return 1;
            lines = temp;

            lines[nlines] = (char *)malloc(i + 1);
            if (lines[nlines] == NULL) return 1;

            copy(lines[nlines], line);
            nlines++;
        }
    }

    printf("-------------------\n");
    for (int i = 0; i < nlines; i++) {
        printf("[%s]\n", lines[i]);
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