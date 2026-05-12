#include <ctype.h>
#include <stdio.h>

int getch();
void ungetch();

int getint(int *pn) {
    int	c;
    while (isspace(c = getch())){
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    int sign = c == '-' ? -1 : 1;
    if (c == '+' || c == '-')
        if (!isdigit(c = getch())) {
            ungetch(c);
            return 0;
        }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + c - '0';
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main() {
    int	result, n;
    if ((result = getint(&n)) == EOF)
        return 0;
    else if (result != 0)
        printf("%d\n", n);
}

#define BUFSIZE	100

char buf[BUFSIZE];
int	bufp = 0;

int getch () {
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch (int c) {
    if (bufp >= BUFSIZE) {
        printf("Error: Too many characters!\n");
    } else {
        buf[bufp++] = c;
    }
}