#include <stdio.h>

void expand(const char s1[], char s2[]) {
    int i = 0, j = 0;

    while (s1[i] != '\0') {
        if (s1[i] == '-' && i > 0 && s1[i + 1] != '\0') {
            char start = s1[i - 1];
            char end = s1[i + 1];

            if ((start >= 'a' && start <= 'z' && end >= 'a' && end <= 'z') ||
                (start >= 'A' && start <= 'Z' && end >= 'A' && end <= 'Z') ||
                (start >= '0' && start <= '9' && end >= '0' && end <= '9')) {
                if (end > start) {
                    char c = start + 1;
                    while (c <= end) {
                        s2[j++] = c++;
                    }
                } else {
                    s2[j++] = s1[i];
                }
                i += 2;
                continue;
            }
        }
        s2[j++] = s1[i++];
    }
    s2[j] = '\0';
}

int main() {
    char s1[] = "a-z";
    char s2[100];
    expand(s1, s2);
    printf("expand(\"%s\") = \"%s\"\n", s1, s2);

    char s1a[] = "a-b-c";
    char s2a[100];
    expand(s1a, s2a);
    printf("expand(\"%s\") = \"%s\"\n", s1a, s2a);

    char s1b[] = "m-z0-8";
    char s2b[100];
    expand(s1b, s2b);
    printf("expand(\"%s\") = \"%s\"\n", s1b, s2b);

    char s1c[] = "-a-z";
    char s2c[100];
    expand(s1c, s2c);
    printf("expand(\"%s\") = \"%s\"\n", s1c, s2c);

    char s1d[] = "a-z-";
    char s2d[100];
    expand(s1d, s2d);
    printf("expand(\"%s\") = \"%s\"\n", s1d, s2d);

    char s1e[] = "A-K";
    char s2e[100];
    expand(s1e, s2e);
    printf("expand(\"%s\") = \"%s\"\n", s1e, s2e);

    return 0;
}