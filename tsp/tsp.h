#ifndef TSP_H
#define TSP_H
    #include <stdbool.h>
    #include "distance_list/distance_list.h"

    void tsp_solve_brute_force(char* filename);
    
    DISTANCE_LIST  *tsp_read_distance_file (char* filename, int *size);
#endif
