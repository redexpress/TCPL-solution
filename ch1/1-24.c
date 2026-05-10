#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 1024

typedef struct {
    char data[STACK_SIZE];
    int top;
} Stack;

void push(Stack *s, char ch) {
    if (s->top < STACK_SIZE - 1) {
        s->top++;
        s->data[s->top] = ch;
    } else {
        fprintf(stderr,"stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        char ch = s->data[s->top];
        s->top--;
        return ch;
    }
}

int main(void) {
    Stack bracket_stack = { .top = -1 };
    int current_char;
    int line = 1;

    while ((current_char = getchar()) != EOF) {
        if (current_char == '\n') {
            line++;
        }

        // handle comments
        if (current_char == '/') {
            int next = getchar();
            if (next == '/') {
                // skip C99 single-line comment
                while ((current_char = getchar()) != '\n' && current_char != EOF);
                if (current_char == '\n') line++;
            } else if (next == '*') {
                // skip multi-line comment
                while (true) {
                    current_char = getchar();
                    if (current_char == EOF) break;
                    if (current_char == '\n') line++;
                    if (current_char == '*') {
                        if ((next = getchar()) == '/') break;
                        ungetc(next, stdin);
                    }
                }
            } else {
                ungetc(next, stdin);
            }
        }
        // handle string
        else if (current_char == '"') {
            while ((current_char = getchar()) != EOF && current_char != '"') {
                if (current_char == '\\') getchar(); // skip escaped characters like \"
                if (current_char == '\n') line++;
            }
        }
        // handler char
        else if (current_char == '\'') {
            while ((current_char = getchar()) != EOF && current_char != '\'') {
                if (current_char == '\\') getchar(); // skip escaped characters like \'
                if (current_char == '\n') line++;
            }
        }
        // handle brackets
        else if (current_char == '(' || current_char == '[' || current_char == '{') {
            push(&bracket_stack, (char)current_char);
        } else if (current_char == ')' || current_char == ']' || current_char == '}') {
            char open = pop(&bracket_stack);

            if (open == '\0') {
                printf("ERR: extra closing bracket '%c' at line %d.\n", current_char, line);
                return EXIT_FAILURE;
            }

            bool is_match = (open == '(' && current_char == ')') ||
                            (open == '[' && current_char == ']') ||
                            (open == '{' && current_char == '}');

            if (!is_match) {
                printf("ERR: mismatched bracket at line %d. Found '%c' for '%c'.\n",
                        line, current_char, open);
                return EXIT_FAILURE;
            }
        }
    }

    // final validation
    if (bracket_stack.top >= 0) {
        printf("ERR: unclosed bracket '%c' detected at end of file.\n", pop(&bracket_stack));
        return EXIT_FAILURE;
    }

    printf("Analysis Complete: No basic syntax errors (brackets/quotes/comments).\n");
    return EXIT_SUCCESS;
}