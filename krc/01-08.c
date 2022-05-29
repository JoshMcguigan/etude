#include <stdio.h>

int main() {
    int c, blanks = 0, tabs = 0, newlines = 0;

    while ((c = getchar()) != EOF) {
        switch (c) {
        case ' ':
            blanks++;
            break;
        case '\t':
            tabs++;
            break;
        case '\n':
            newlines++;
            break;
        }
    }

    printf("blanks: %d\n", blanks);
    printf("tabs: %d\n", tabs);
    printf("newlines: %d\n", newlines);

    return 0;
}
