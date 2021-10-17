#ifndef DISTANCE_MATRIX_H
#define DISTANCE_MATRIX_H
#include <stdbool.h>

#define MAX_SIZE 10

//avisa o programa que existe um novo tipo de dados que é o CIRCULO
typedef struct distance_matrix_ DISTANCE_MATRIX;

DISTANCE_MATRIX distance_matrix_read_distance_matrix_file(char *filename);

int distance_matrix_get_node_distance(DISTANCE_MATRIX *distance_matrix, int i, int j);

int distance_matrix_get_size(DISTANCE_MATRIX *distance_matrix);
#endif
