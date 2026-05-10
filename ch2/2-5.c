#include <stdio.h>
#include <string.h>

int any_lib(const char *s1, const char *s2) {
    size_t pos = strcspn(s1, s2);
    return s1[pos] != '\0' ? (int)pos : -1;
}

int any(const char *s1, const char *s2) {
    for (int i = 0; s1[i] != '\0'; i++) {
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) return i;
        }
    }
    return -1;
}

int main() {
    char s1[] = "hello world";
    char s2[] = "dw";
    printf("any     %d\n", any(s1, s2));
    printf("any_lib %d\n", any_lib(s1, s2));
    return 0;
}



