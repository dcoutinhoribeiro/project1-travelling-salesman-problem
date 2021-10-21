#ifndef TSP_H
#define TSP_H
    #include <stdbool.h>
    #include "distance_list/distance_list.h"

    int tsp_get_shortest_route_from_file(char* filename);

    void tsp_print_shortest_route_from_file(char* filename);
    
    DISTANCE_LIST  *tsp_read_distance_file (char* filename);
#endif
