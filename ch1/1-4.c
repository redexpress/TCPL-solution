#include <stdio.h>

int main(void) {
    int lower = -60;
    int upper = 200;
    int step = 20;
    float celsius = lower;
    printf("celsius fahr\n");
    while (celsius <= upper) {
        float fahr = celsius * 9.0 / 5.0 + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}