#include <stdlib.h>
#include <stdio.h>
#include "distance_matrix.h"

struct distance_matrix_ {
    int size;
    int matrix[MAX_SIZE][MAX_SIZE];
};

int distance_matrix_get_size(DISTANCE_MATRIX *distance_matrix)
{
    return distance_matrix->size;
}
