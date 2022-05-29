#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib/vector.h"

void check_parens(char *input);
void print_err(char *input, char *err_char);

int main() {
    check_parens("())");
    check_parens("()))");
    check_parens("(()");
    check_parens("(()())()");
}

void check_parens(char *input) {
    Vector open_parens = vector_new();

    bool found_error = false;

    for (char *current_char = input; *current_char != 0; current_char++) {
        if (*current_char == '(') {
            vector_push(&open_parens, current_char);
        } else if (*current_char == ')') {
            char *matching_open_paren = (char *)vector_pop(&open_parens);

            if (matching_open_paren == NULL) {
                found_error = true;
                print_err(input, current_char);
                break;
            }
        }
    }

    char *matching_open_paren = (char *)vector_pop(&open_parens);

    if (matching_open_paren != NULL) {
        found_error = true;
        print_err(input, matching_open_paren);
    }

    if (!found_error)
        printf("%s Balanced\n", input);

    printf("\n");

    vector_free(&open_parens);
}

void print_err(char *input, char *err_char) {
    printf("%s Not balanced\n", input);

    size_t error_location = err_char - input;
    for (int i = 0; i < error_location; i++)
        printf(" ");
    printf("^ Mismatch here\n");
}
