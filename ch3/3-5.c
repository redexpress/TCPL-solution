#include <limits.h>
#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itob(int n, char s[], int b) {
    unsigned v;
    if (n > 0) {
        v = n;
    } else {
        v = (n == INT_MIN) ? (unsigned)n : (unsigned)-n;
    }
    int i = 0;
    do {
        if (v % b < 10) {
            s[i++] = v % b + '0';
        } else {
            s[i++] = v % b + 'a' - 10;
        }
    } while ((v /= b) > 0);
    if (n < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    int a = 123456;
    char s[20];
    itob(a, s, 16);
    printf("%x=%s\n", a , s);
}
