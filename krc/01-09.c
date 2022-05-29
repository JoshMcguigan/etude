#include <stdio.h>

int main() {
    int c, prev_char = EOF, blanks = 0, tabs = 0, newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' && prev_char == ' ')
            continue;

        putchar(c);
        prev_char = c;
    }

    return 0;
}
