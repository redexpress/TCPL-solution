#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 50

#ifdef _WIN32
typedef long long ssize_t;

ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
    size_t pos;
    int c;
    if (*lineptr == NULL || *n == 0) {
        *n = 128;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL) return -1;
    }

    pos = 0;
    while ((c = fgetc(stream)) != EOF) {
        if (pos + 1 >= *n) {
            size_t new_size = *n + 64;
            char *new_ptr = (char *)realloc(*lineptr, new_size);
            if (new_ptr == NULL) return -1;
            *lineptr = new_ptr;
            *n = new_size;
        }
        (*lineptr)[pos++] = c;
        if (c == '\n') break;
    }
    if (c == EOF && pos == 0) return -1;
    (*lineptr)[pos] = '\0';
    return pos;
}
#endif

bool is_blank(char c) {
    return c == ' ' || c == '\t';
}

void printline(char *line, int n) {
    char *p = line;
    int total_len = strlen(line);

    // remove \n in line end
    if (total_len > 0 && line[total_len - 1] == '\n') {
        line[total_len - 1] = '\0';
    }

    while (strlen(p) > n) {
        int last_blank = -1;
        // find last blank in first n
        for (int i = 0; i < n; i++) {
            if (is_blank(p[i])) {
                last_blank = i;
            }
        }

        if (last_blank != -1) {
            printf("%.*s\n", last_blank + 1, p);
            p += (last_blank + 1);
        } else {
            // can't find blank, cut width
            printf("%.*s-\n", n, p);
            p += n;
        }

        while (is_blank(*p)) p++;
    }

    if (*p != '\0') {
        printf("%s\n", p);
    }
}

int main(void) {
    size_t len = 0;
    char *line = NULL;
    const int width = 30;
    if (getline(&line, &len, stdin) != -1) {
        printline(line, width);
    }
    free(line);
    return 0;
}

