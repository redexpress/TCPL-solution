#!/bin/bash
gcc -std=c99 1-24.c

echo "1: Professional Valid"
./a.out <<EOF
#include <stdio.h>
#define GUARD(x) { x; }
/* 1. Comment traps: { [ ( */
int main() {
    char *s = "String trap: { [ ( \" ";
    char c = '(', *p = "/* ) */";
    int arr[2][1] = { {1}, {2} }; // 2D nested
    if ( (1 + 1) == 2 ) GUARD(printf("Pass\n"));
    return 0;
}
EOF
[ $? -eq 0 ] && echo "PASS" || echo "FAIL"

echo "2: Escape Traps"
./a.out <<EOF
char *s = "\\\\"; // Backslash trap
char *quote = " \" { "; // Escaped quote
char a = '{', b = '}', c = '\"';
EOF
[ $? -eq 0 ] && echo "PASS" || echo "FAIL"

echo "3: Logical Mismatch"
./a.out <<EOF
int main() {
    int x = ( [ 1 + 2 ) ] ; // Correct count, wrong order
}
EOF
[ $? -ne 0 ] && echo "PASS" || echo "FAIL"


echo "4: Interleaved Syntax"
./a.out <<EOF
/* " */  int x;  /* " */
char *s = " /* ";
// " {
int y = (int)'"';
EOF
[ $? -eq 0 ] && echo "PASS" || echo "FAIL"

echo "5: Deep Nesting/EOF"
./a.out <<EOF
{{{{(((([[]]))))
EOF
[ $? -ne 0 ] && echo "PASS" || echo "FAIL"

echo "6: Minimalist"
./a.out <<'EOF'
int main(){}
EOF
[ $? -eq 0 ] && echo "PASS" || echo "FAIL"

echo "7: 1-24.c"
cat 1-24.c | ./a.out
[ $? -eq 0 ] && echo "PASS" || echo "FAIL"

