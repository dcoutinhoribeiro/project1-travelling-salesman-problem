/*route.h*/
#ifndef ROUTE_H
    #define ROUTE_H
    #define INT_MAX 2147483647
    #include <stdbool.h>
    #include "../distance_matrix/distance_matrix.h"
    #include "../path/path.h"

    typedef struct route_ ROUTE;

    int route_get_distance(ROUTE *route, DISTANCE_MATRIX *distance_matrix); //
    int route_get_size(ROUTE *route); //
    int  route_get_larg_j_lg_i(ROUTE *route, int i); //

    void route_free(ROUTE **route);
    void route_print();

    bool route_set_size(ROUTE *route, int size); //
    bool route_set_path(ROUTE *route, int *path); //
    bool route_is_not_last_permutation(ROUTE *route); //

    PATH *route_get_path(ROUTE *route); //

    ROUTE *route_new(int size, PATH *path); //
    ROUTE *route_get_best_route(DISTANCE_MATRIX *distance_matrix); //
    ROUTE *get_next_permutation(ROUTE *route); //
    
#endif
