#include <stdio.h>

int lower_by_if (int c) {
    if (c >= 'A' && c<= 'Z' )
        return c + 'a' - 'A';
    else
        return c;
}

int lower (int c) {
    return (c >= 'A' && c<= 'Z') ? (c + 'a' - 'A') : c;
}

int main() {
    printf("%c %c\n", lower('C'), lower('#'));
    return 0;
}


