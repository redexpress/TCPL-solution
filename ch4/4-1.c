#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]) {
    for (int i = strlen (s); i >= 0; i--) {
        for (int j = i, k = strlen(t) - 1;
                j >= 0 && k >= 0 && s[j] == t[k];
                j--, k--) {
            if (k == 0) {
                return j;
            }
        }
    }
    return -1;
}

int main () {
    char s[] = "Hello World!";
    char t[] = "Wor";
    printf ("%d", strrindex (s, t));
    return 0;
}