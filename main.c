#include <stdio.h>
#include "tsp/tsp.h"

void main (int argc, char **argv){
    int start;

    char *filename;
    printf("\nDigite o nome do arquivo com a matrix de distancias: \n");
    scanf('%s', filename);

    tsp_print_shortest_route_from_file(filename);

    return;
}