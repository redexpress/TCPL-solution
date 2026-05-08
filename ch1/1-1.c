#include <stdio.h>

int main(void) {
    /*
     GCC 13.3 missing semicolor(;) error:
    1-1.c: In function ‘main’:
1-1.c:4:29: error: expected ‘;’ before ‘}’ token
    4 |     printf("hello, world\n")
      |                             ^
      |                             ;
    5 | }
      | ~
     */
    printf("hello, world\n");
}