#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

void print_by_headers() {
    printf("char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char: 0 to %u\n", UCHAR_MAX);

    printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: 0 to %u\n", USHRT_MAX);

    printf("int: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: 0 to %u\n", UINT_MAX);

    printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: 0 to %lu\n", ULONG_MAX);

    printf("long long: %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long: 0 to %llu\n", ULLONG_MAX);

    printf("float: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("double: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("double: %Le to %Le\n", LDBL_MIN, LDBL_MAX);
}

void print_by_calc() {
    // UNSIGNED
    unsigned char      u_c  = (unsigned char)~0;
    unsigned short     u_s  = (unsigned short)~0;
    unsigned int       u_i  = (unsigned int)~0;
    unsigned long      u_l  = (unsigned long)~0;
    unsigned long long u_ll = (unsigned long long)~0;

    // SIGNED
    signed char c_max = (signed char)(u_c >> 1);
    signed char c_min = (signed char)~c_max;

    short s_max = (short)(u_s >> 1);
    short s_min = (short)~s_max;

    int i_max = (int)(u_i >> 1);
    int i_min = (int)~i_max;

    long l_max = (long)(u_l >> 1);
    long l_min = (long)~l_max;

    long long ll_max = (long long)(u_ll >> 1);
    long long ll_min = (long long)~ll_max;

    // PRINTING (Matched types with variables)
    printf("char: %d to %d\n", c_min, c_max);
    printf("unsigned char: 0 to %u\n", u_c);

    printf("short: %d to %d\n", s_min, s_max);
    printf("unsigned short: 0 to %u\n", u_s);

    printf("int: %d to %d\n", i_min, i_max);
    printf("unsigned int: 0 to %u\n", u_i);

    printf("long: %ld to %ld\n", l_min, l_max);
    printf("unsigned long: 0 to %lu\n", u_l);

    printf("long long: %lld to %lld\n", ll_min, ll_max);
    printf("unsigned long long: 0 to %llu\n", u_ll);
    // float
    float f_max = 1.0f;
    while (!isinf(f_max * 2.0f)) f_max *= 2.0f;
    float f_delta = f_max / 2.0f;
    while (f_delta > 0) {
        if (!isinf(f_max + f_delta)) f_max += f_delta;
        f_delta /= 2.0f;
    }

    // double
    double d_max = 1.0;
    while (!isinf(d_max * 2.0)) d_max *= 2.0;
    double d_delta = d_max / 2.0;
    while (d_delta > 0) {
        if (!isinf(d_max + d_delta)) d_max += d_delta;
        d_delta /= 2.0;
    }

    // long double
    long double ld_max = 1.0L;
    while (!isinf(ld_max * 2.0L)) ld_max *= 2.0L;

    long double ld_delta = ld_max / 2.0L;
    while (ld_delta > 0) {
        if (!isinf(ld_max + ld_delta)) ld_max += ld_delta;
        ld_delta /= 2.0L;
    }

    printf("float max (calc): %e\n", f_max);
    printf("double max (calc): %e\n", d_max);
    printf("long double max (calc): %Le\n", ld_max);
}

int main() {
    print_by_headers();
    print_by_calc();
    return EXIT_SUCCESS;
}