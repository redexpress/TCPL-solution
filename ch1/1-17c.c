#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kvec.h"

#include <stdio.h>
#include <stdlib.h>

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

int main(void) {
    const int LINE_SIZE = 80;

    char *line = NULL;
    size_t len = 0;
    kvec_t(char *) lines;

    kv_init(lines);

    while (getline(&line, &len, stdin) != -1) {
        if (strlen(line) - 1 > LINE_SIZE) {
            char *new_line = (char *)malloc(strlen(line) + 1);
            if (new_line == NULL) {
                break; 
            }
            strcpy(new_line, line);
            kv_push(char*, lines, new_line);
        }
    }

    printf("-------------------\n");
    for (int i = 0; i < lines.n; i++) {
        printf("%s", lines.a[i]);
        free(lines.a[i]);
    }
    kv_destroy(lines);
    free(line);
    return 0;
}