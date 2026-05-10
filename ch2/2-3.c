#include <stdio.h>
#include <stdlib.h>

long htoi_lib(const char s[]) {
    return strtol(s, NULL, 16);
}

int htoi(const char s[]) {
    int i = 0;
    int n = 0;
    // skip optional 0x or 0X prefix
    if (s[i] == '0') {
        ++i;
        if (s[i] == 'x' || s[i] == 'X') {
            ++i;
        }
    }
    // hex digits
    for (; s[i] != '\0'; ++i) {
        int digit;
        if (s[i] >= '0' && s[i] <= '9') {
            digit = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            digit = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            digit = s[i] - 'A' + 10;
        } else {
            // stop at invalid hex character
            break;
        }

        n = 16 * n + digit;
    }

    return n;
}

int main() {
    char *tests[] = {"0x1A3F", "0XdeBEEF", "0X2bF7"};
    for (int i = 0; i < 3; ++i) {
        printf("htoi_lib(\"%s\") = %ld\n", tests[i], htoi_lib(tests[i]));
        printf("htoi(\"%s\") = %d\n", tests[i], htoi(tests[i]));
    }
    return 0;
}

