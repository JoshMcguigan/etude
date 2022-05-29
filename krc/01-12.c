#include <assert.h>
#include <stdio.h>

#define IN 0
#define OUT 1

int main() {
    int c;
    int state = OUT;

    while ((c = getchar()) != EOF) {
        if (state == IN && (c == ' ' || c == '\n' || c == '\t')) {
            state = OUT;
            putchar('\n');
        } else {
            state = IN;
            putchar(c);
        }
    }

    return 0;
}
