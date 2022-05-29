#include <assert.h>
#include <stdio.h>

#define IN 0
#define OUT 1

int wc(char *s) {
    int wc, state;

    wc = 0;
    state = OUT;

    while (*s != '\0') {
        if (*s == ' ' || *s == '\n' || *s == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            wc++;
        }
        s++;
    }

    return wc;
}

int main() {
    assert(3 == wc("foo bar baz"));

    return 0;
}
