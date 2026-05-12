#include <stdio.h>

int strend(char *s, char *t) {
    char *p = s;
    char *q = t;
    while (*p) p++; // move to s end
    while (*q) q++; // move to t end
    while (q != t && p !=s) {
        p--;
        q--;
        if (*p != *q) {
            return 0;
        }
    }
    return q == t ? 1 : 0;
}

int main(void) {
    char *s1="foobar";
    char *s2="bar";
    char *s3 ="hi";
    printf("%d, %d\n", strend(s1, s2), strend(s1, s3));
}