#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define NAME 'a'

int getop(char []);
int getch();
void ungetch(int);

void push(double);
double pop();
void mathfunc(char []);

int main() {
    int type;
    double op2;
    char s[MAXOP];
    while((type=getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0)
                push(pop() / op2);
            else
                printf("error: zero divisor");
            break;
        case '%':
            op2 = pop();
            {
                int op1 = pop();
                if (op2 != 0)
                    push(op1 - op2 * ((int)(op1/op2)));
                else
                    printf("error: zero divisor\n");
            }
            break;
        case NAME:
            mathfunc(s);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

int getop(char s[ ] ) {
    int i, c;
    while ( (s[0] = c = getch() ) == ' ' || c == '\t' )
        ;
    s[1] = '\0';
    if ( !isdigit( c ) && c != '.' && !isalpha(c) )
        return c;
    i = 0;
    if ( isdigit( c ) )
        while ( isdigit(s[++i] = c = getch()) ) {
        }
    if (c == '.' )
        while ( isdigit(s[++i] = c = getch()) ) {
        }
    if ( isalpha(c) )
        while ( isalpha(s[++i] = c = getch()) ) {
        }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    if ( isalpha(s[0]) )
        return NAME;
    return NUMBER;
}

void push (double d) {
    if ( sp < MAXVAL )
        val[sp++] = d;
    else
        printf ( "error: stack full, can't push %g\n", d);
}

double pop(void) {
    if ( sp > 0 )
        return val[--sp];
    printf ( "error: stack empty\n" );
    return 0.0;
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

void mathfunc(char s[]) {
    double op2;
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "tan") == 0)
        push(tan(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "log") == 0)
        push(log(pop()));
    else if (strcmp(s, "sqrt") == 0)
        push(sqrt(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else if (strcmp(s, "fabs") == 0)
        push(fabs(pop()));
    else
        printf("error: unknown function %s\n", s);
}