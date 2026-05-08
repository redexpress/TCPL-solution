#include <stdio.h>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <stdlib.h>
#endif

#ifdef _WIN32
void restore_terminal() {}
#else
struct termios oldt;
void restore_terminal() {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
#endif

int main() {
    int ch;

#ifndef _WIN32
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt);
    atexit(restore_terminal);

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#endif

    while (1) {
#ifdef _WIN32
        ch = _getch();
        if (ch == 13) {
            putchar('\n');
            fflush(stdout);
            continue;
        }
        if (ch == 26) break;
#else
        ch = getchar();
        if (ch == EOF) break;
#endif

        if (ch == '\t') {
            putchar('\\'); putchar('t');
        } else if (ch == '\b' || ch == 127) {
            putchar('\\'); putchar('b');
        } else if (ch == '\\') {
            putchar('\\'); putchar('\\');
        } else {
            putchar(ch);
        }
        fflush(stdout);
    }

    return 0;
}