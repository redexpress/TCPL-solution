#include <ctype.h>
#include <stdio.h>

double atof (char s[]) {
    double	val, power;
    int	i, sign;

    for (i = 0; isspace(s[i]); i++) {
    }
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (tolower(s[i]) == 'e') {
        int sign_e = s[++i] == '-' ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')
            i++;
        int e = 0;
        for (e = 0; isdigit(s[i]); i++) {
            e = e * 10 + s[i] - '0';
        }
        if (sign_e < 0) {
            for (int i = 0; i < e; i++) {
                power *= 10.0;
            }
        } else {
            for (int i = 0; i < e; i++) {
                power /= 10.0;
            }
        }
    }

    return sign * val / power;
}

int main () {
    char s[] = "314159e-5";
    printf("%g\n", atof(s));
    return 0;
}