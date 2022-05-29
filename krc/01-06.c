#include <stdio.h>

int main() {
    int c;

    while (1) {
        c = getchar();
        int equality_val = c != EOF;
        printf("%d", equality_val);

        if (equality_val == 0) {
            break;
        }
    }

    return 0;
}
