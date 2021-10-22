/*route.h*/
#ifndef ROUTE_H
    #define ROUTE_H
    #define INT_MAX 2147483647
    #include <stdbool.h>
    #include "../tsp/distance_list/distance_list.h"
    #include "../path/path.h"

    typedef struct route_ ROUTE;

    int route_get_distance(ROUTE *route, DISTANCE_LIST *distance_list); //
    int route_get_size(ROUTE *route); //
    int  route_get_larg_j_lg_i(ROUTE *route, int i); //
    int route_get_larg_lgt (ROUTE *route);

    void route_free(ROUTE **route);
    void route_print(ROUTE *route, DISTANCE_LIST *distance_list);
    void route_print_best_route(DISTANCE_LIST *distance_list, int size);

    bool route_set_size(ROUTE *route, int size); //
    bool route_set_path(ROUTE *route, PATH *path); //
    bool route_is_not_tail_permutation(ROUTE *route); //

    PATH *route_get_path(ROUTE *route); //

    ROUTE *route_new(int size, PATH *path); //
    ROUTE *route_get_best_route(DISTANCE_LIST *distance_list, int size); //
    ROUTE *route_get_next_permutation(ROUTE *route); //
    
#endif
