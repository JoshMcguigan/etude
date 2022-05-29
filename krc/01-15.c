#include <stdio.h>

float deg_c_from(float deg_f) { return (5.0 / 9.0) * (deg_f - 32.0); }

int main() {
    int lower = 0;
    int higher = 300;
    int step = 20;

    printf(" f  |   c\n");
    printf("-----------\n");
    for (float f = lower; f <= higher; f += step) {
        printf("%3.0f  %6.1f\n", f, deg_c_from((float)f));
    }

    return 0;
}
