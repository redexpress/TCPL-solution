#include <stdio.h>

int binsearch(int x, int v[], int n) {
    int low = 0, high = n - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (v[mid] < x)
            low = mid + 1;
        else
            high = mid;
    }
    return (v[low] == x) ? low : -1;
}

int main() {
    int v[] = {1, 3, 5, 7, 9};
    int n = sizeof(v) / sizeof(v[0]);
    int x = 5;
    int index = binsearch(x, v, n);
    if (index != -1) {
        printf("Found %d at index %d\n", x, index);
    } else {
        printf("%d not found in array\n", x);
    }
    return 0;
}

