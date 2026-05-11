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

void itoa(int n, char s[]) {
    unsigned v;
    if (n > 0) {
        v = n;
    } else {
        v = (n == INT_MIN) ? n : -n;
    }
    int i = 0;
    do {
        s[i++] = v % 10 + '0';
    } while ((v /= 10) > 0);
    if (n < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    int a = INT_MIN;
    char s[20];
    itoa(a, s);
    printf("itoa(%d)=\"%s\"\n", a, s);
}

