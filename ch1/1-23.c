#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
gcc 1-23.c && ./a.out 1-23.c > 1-23b.c
gcc 1-23b.c && ./a.out 1-23.c > 1-23c.c
diff 1-23c.c 1-23b.c
if [ $? = 0 ] ; then
    echo SUCCESS
else
    echo FAILURE
fi
*/
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;         // exit with error
    }

    FILE *fp = fopen(argv[1], /* mode r is readonly */ "r");
    if (!fp) {
        fprintf(stderr, "Cannot open file: %s\n", argv[1]);
        return 1;
    }
    bool in_string = false;
    bool in_char = false;
    bool in_line = false;  /* inside // */
    int next;
    int block_depth = 0;  // nested /* */ depth
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        // handle block comment (non-nesting)
        if (block_depth) {
            if (ch == '*') {
                next = fgetc(fp);
                if (next == '/') {
                    block_depth = 0;
                } else if (next != EOF) {
                    ungetc(next, fp);
                }
            }
            continue;
        }

        /* handle line comment */
        if (in_line) {
            if (ch == '\n') {
                in_line = false;
                putchar('\n');
            }
            continue;
        }

        // inside string literal
        if (in_string) {
            putchar(ch);
            if (ch == '\\') {
                next = fgetc(fp);
                if (next != EOF) putchar(next);
            } else if (ch == '"') {
                in_string = false;
            }
            continue;
        }

        /* inside character constant */
        if (in_char) {
            putchar(ch);
            if (ch == '\\') {
                next = fgetc(fp);
                if (next != EOF) putchar(next);
            } else if (ch == '\'') {
                in_char = false;
            }
            continue;
        }

        // normal code: detect start of comment
        if (ch == '/') {
            next = fgetc(fp);
            if (next == '*') {
                block_depth = 1;
            } else if (next == '/') {
                in_line = true;
            } else {
                putchar(ch);
                if (next != EOF) putchar(next);
            }
        } else if (ch == '"') {
            in_string = true;
            putchar(ch);
        } else if (ch == '\'') {
            in_char = true;
            putchar(ch);
        } else {
            putchar(ch);
        }
    }

    fclose(fp);
    return 0;
}

// A line comment after main

#ifdef RUN_TEST2
void test_function2() {
    int a = 10;
    /*
    a = 100;
    /* nested comment */
    a = 200;
    */
}
#endif