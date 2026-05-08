#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int nlines = 0;
    const int LINE_SIZE = 80;

    char *line = NULL;
    size_t len = 0;
    char **lines = NULL;

    while (getline(&line, &len, stdin) != -1) {
        if (strlen(line) - 1 > LINE_SIZE) {
            char **temp = (char **)realloc(lines, (nlines + 1) * sizeof(char *));
            if (temp == NULL) {
                free(line);
                free(lines);
                return 1;
            }
            lines = temp;

            lines[nlines] = (char *)malloc(strlen(line) + 1);
            if (lines[nlines] == NULL) return 1;
            strcpy(lines[nlines], line);
            nlines++;
        }
    }

    printf("-------------------\n");
    for (int i = 0; i < nlines; i++) {
        printf("%s", lines[i]);
        free(lines[i]);
    }
    free(lines);
    free(line);
    return 0;
}