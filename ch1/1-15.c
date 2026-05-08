#include <stdio.h>

float fahr_to_celsius(float fahr) {
    return 5.0 / 9.0 * (fahr - 32.0);
}

int main(void) {
    int lower = 0;
    int upper = 300;
    int step = 20;
    float fahr = lower;
    printf("fahr celsius\n");
    while (fahr <= upper) {
        float celsius = fahr_to_celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }
    return 0;
}