#include <stdio.h>

int binsearch(int x, int v[], int n) {
    int index = n / 2;
    int low;
    int high;

    while (1) {
        int midpoint_value = v[index];

        if (midpoint_value == x)
            return index;
        else if (midpoint_value > x) {
            low = 0;
            high = n / 2 - 1;
        } else {
            low = n / 2 + 1;
            high = n;
        }

        if (low == high) {
            if (v[low] == x)
                return low;
            else
                return -1;
        }

        index = (low + high) / 2;
    }
}

int main() { return binsearch(0, (int[]){0, 1, 2}, 3); }
