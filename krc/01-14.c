#include <limits.h>
#include <stdio.h>

#define MIN_PRINTABLE_CHAR 32
#define NUM_PRINTABLE_CHARS (CHAR_MAX - MIN_PRINTABLE_CHAR)

int main() {
    int c;
    int count[NUM_PRINTABLE_CHARS];

    for (int i = 0; i < NUM_PRINTABLE_CHARS; i++)
        count[i] = 0;

    while ((c = getchar()) != EOF) {
        count[(char)c - MIN_PRINTABLE_CHAR]++;
    }

    for (int i = 0; i < NUM_PRINTABLE_CHARS; i++) {
        printf("'%c': %d\n", (char)i + MIN_PRINTABLE_CHAR, count[i]);
    }

    return 0;
}
