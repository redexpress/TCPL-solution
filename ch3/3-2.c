#include <stdio.h>
#include <string.h>

void escape(char s[], const char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        case '\\':
            s[j++] = '\\';
            s[j++] = '\\';
            break;
        case '\"':
            s[j++] = '\\';
            s[j++] = '"';
            break;
        default:
            s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0';
}

void unescape(char s[], const char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        if (t[i] == '\\' && t[i + 1] != '\0') {
            switch (t[++i]) {
            case 'n':
                s[j++] = '\n';
                break;
            case 't':
                s[j++] = '\t';
                break;
            case '\\':
                s[j++] = '\\';
                break;
            case '"':
                s[j++] = '"';
                break;
            default:
                s[j++] = '\\';
                s[j++] = t[i];
            }
        } else {
            s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0';
}

int main() {
    char src[] = "hello\tworld\n\"foo\"\\bar";
    char dest[100];
    char origin[100];
    escape(dest, src);
    unescape(origin, dest);
    printf("src: %s\n", src);
    printf("dest: %s\n", dest);
    printf("origin: %s\n", origin);
    printf("src == origin: %s\n", strcmp(src, origin) == 0 ? "true" : "false");
    return 0;
}