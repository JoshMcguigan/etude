#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib/vector.h"

typedef struct {
    Vector values, minimums;
} VectorTrackMin;

VectorTrackMin vector_track_min_new() {
    return (VectorTrackMin){vector_new(), vector_new()};
}

size_t vector_track_min_min(VectorTrackMin *vector) {
    return (size_t)vector_peek(&vector->minimums);
}

void vector_track_min_push(VectorTrackMin *vector, size_t number) {
    if ((vector_length(&vector->values) &&
         vector_track_min_min(vector) >= number) ||
        !vector_length(&vector->values)) {
        vector_push(&vector->minimums, (void *)number);
    }
    vector_push(&vector->values, (void *)number);
}

size_t vector_track_min_pop(VectorTrackMin *vector) {
    size_t number = (size_t)vector_pop(&vector->values);

    if (number == vector_track_min_min(vector)) {
        vector_pop(&vector->minimums);
    }

    return number;
}

void vector_track_min_free(VectorTrackMin *vector) {
    vector_free(&vector->values);
    vector_free(&vector->minimums);
}

int main() {
    VectorTrackMin v = vector_track_min_new();

    vector_track_min_push(&v, 10);
    assert(vector_track_min_min(&v) == 10);

    vector_track_min_push(&v, 5);
    vector_track_min_push(&v, 5);
    assert(vector_track_min_min(&v) == 5);

    vector_track_min_pop(&v);
    assert(vector_track_min_min(&v) == 5);

    vector_track_min_pop(&v);
    assert(vector_track_min_min(&v) == 10);

    vector_track_min_free(&v);
}
