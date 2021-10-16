/*route.h*/
#ifndef ROUTE_H
    #define ROUTE_H
    #include <stdbool.h>
    #include "../distance_matrix/distance_matrix.h"

    //avisa o programa que existe um novo tipo de dados que é o CIRCULO
    typedef struct route_ ROUTE;

    void route_print_best_route(int start, DISTANCE_MATRIX *matrix_distance);

    ROUTE route_get_next_permutation(ROUTE *route);

    bool  route_is_last_permutation(ROUTE *route);

    int   route_get_distance(ROUTE *route);

    ROUTE route_get_best_route(ROUTE *route);

#endif
