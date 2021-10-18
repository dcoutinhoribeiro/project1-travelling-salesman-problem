#include <stdio.h>
#include "distance_matrix/distance_matrix.h"
#include "route/route.h"

void main (int argc, char **argv){
    DISTANCE_MATRIX *distance_matrix;

    int start;

    char *filename;
    printf("\nDigite o nome do arquivo com a matrix de distancias: \n");
    scanf('%s', filename);

    distance_matrix = distance_matrix_read_distance_matrix_file(filename);

    printf("\nDigite a cidade de origem: \n");
    scanf('%d', &start);

    route_print_best_route(distance_matrix);

    return;
}