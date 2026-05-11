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

void itob(int n, char s[], int min_width) {
    unsigned v;
    if (n > 0) {
        v = n;
    } else {
        v = (n == INT_MIN) ? (unsigned)n : (unsigned)-n;
    }
    int i = 0;
    do {
        s[i++] = v % 10 + '0';
    } while ((v /= 10) > 0);
    if (n < 0) {
        s[i++] = '-';
    }
    while (i < min_width) {
        s[i++] = '0';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    int a = 123456;
    char s[20];
    itob(a, s, 8);
    printf("%d=%s\n", a , s);
}
