#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "route.h"
#include "../path/path.h"
#include "../path/node/node.h"
#include "../distance_matrix/distance_matrix.h"

struct route_ {
    int size; 
    PATH *path;
};

bool route_set_size(ROUTE *route, int size) {
    if (route != NULL){
        route->size = size;
        return true;
    }
    return false;
}

bool route_set_path(ROUTE *route, int *path) {
    if (route != NULL){
        route->path = path;
        return true;
    }
    return false;
}


ROUTE *route_new(int size, PATH *path) {
    ROUTE *route;
    route = (ROUTE *) malloc(sizeof(ROUTE));
          
    return 
        route != NULL && 
        route_set_size(route, size) &&
        route_set_path(route, path) 
            ? route : NULL;
}

ROUTE *get_next_permutation(ROUTE *route) {
    PATH *path;
    int j, larg_j;

    if(route == NULL) return NULL;

    j = route_get_larg_j_lg_i(route, 1);

    if(j == -1) return NULL; 

    larg_j = route_get_larg_j_lg_i(route, j);
    path = path_reverse(path_swap(route_get_path(path), j, larg_j), j+1);

    return path != NULL && route_set_path(route, path) ? route : NULL;
};

int route_get_larg_j_lg_i(ROUTE *route, int i){
    int i, j = -1, size = path_get_size(route_get_path(route));
    PATH *path = route_get_path(route);

    for(i = i; i < size; i++){
        NODE *node_a, *node_b;

        node_a = path_search(i - 1, path);
        node_b = path_search(i, path);
        
        if (node_get_key(node_a) < node_get_key(node_b)){
            j = i - 1;
        }
    }

    return j;
}

bool route_is_not_last_permutation(ROUTE *route) {
    route != NULL && route_get_largest_largest(route) == -1 ? false : true;
}

PATH *route_get_path(ROUTE *route) {
    return route != NULL ? route->path : NULL;
}

int route_get_distance(ROUTE *route, DISTANCE_MATRIX *distance_matrix) {
    if(route == NULL || distance_matrix == NULL) return NULL;

    int size, i, route_distance = 0;
    size = path_get_size(route_get_path(route));

    for(i = 1; i <= size; i++){
        route_distance += distance_matrix_get_node_distance(distance_matrix, i - 1, i);
    }
    route_distance += distance_matrix_get_node_distance(distance_matrix, 1, size); 

    return route_distance;
}

ROUTE *route_get_best_route(int start, DISTANCE_MATRIX *distance_matrix) {
    if(distance_matrix == NULL) return NULL;

    int size, shortest_distance_so_far = INT_MAX;
    ROUTE *route;
    PATH *path;

    size = distance_matrix_get_size(distance_matrix);
    path = path_new(start, size);

    if(path == NULL) return NULL;

    route = route_new(size, path);

    do {
        route = route_get_next_permutation(route);
        if (route == NULL) break;

        int route_distance = route_get_distance(route, distance_matrix);

        if (shortest_distance_so_far > route_distance) continue;

        shortest_distance_so_far = route_distance;
        path_copy(route_get_path(route), path);
        
    } while(route_is_not_last_permutation(route));

    return route != NULL ? route : NULL;    
}