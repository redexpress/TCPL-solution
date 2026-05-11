#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void push(double);
double pop();
double top();
double duplicate_top();
void swap_top2();
void clear_stack();
int stack_size();

int main() {
    printf("%d\n", stack_size());
    push(1.0);                   // | 1.0
    push(2.0);                   // | 1.0 2.0
    printf("%lf\n", top());
    swap_top2();                   // | 2.0 1.0
    printf("%lf\n", top());
    pop();                         // | 2.0
    printf("%d\n", stack_size());
    printf("%lf\n", top());
    clear_stack();                 // |
    printf("%d\n", stack_size());
    return 0;
    /* Output:
    0
    2.000000
    1.000000
    1
    2.000000
    0
    */
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push (double d) {
    if ( sp < MAXVAL )
        val[sp++] = d;
    else
        printf ( "error: stack full, can't push %g\n", d);
}

double pop() {
    if ( sp > 0 )
        return val[--sp];
    printf ( "error: stack empty\n" );
    return 0.0;
}

double top() {
    if (sp > 0)
        return val[sp - 1];
    printf ( "error: stack empty\n" );
    return 0.0;
}

double duplicate_top() {
    double top_val = top();
    push(top_val);
}

void swap_top2() {
    double top = pop();
    double top2 = pop();
    push(top);
    push(top2);
}

void clear_stack() {
    sp = 0;
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

int stack_size() {
    return sp;
}