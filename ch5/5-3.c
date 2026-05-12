#include <stdio.h>

void my_strcat(char *s, char *t) {
    while (*s) {
        s++;
    }
    while ((*s++ = *t++)) {
    }
}

int main(void) {
    char s[20] = "Hello ";
    char t[] = "World";
    printf("before: s = %s\n", s);
    my_strcat(s, t);
    printf("after : s = %s\n", s);
    return 0;
}