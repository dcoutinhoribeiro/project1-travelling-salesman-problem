#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "route.h"
#include "../tsp/distance_list/distance_list.h"
#include "../path/path_node/path_node.h"
#include "../path/path.h"

struct route_
{
    int size;
    PATH *path;
};

bool route_set_size(ROUTE *route, int size)
{
    if (route != NULL)
    {
        route->size = size;
        return true;
    }
    return false;
}

bool route_set_path(ROUTE *route, PATH *path)
{
    if (route != NULL)
    {
        route->path = path;
        return true;
    }
    return false;
}

ROUTE *route_new(int size, PATH *path)
{
    ROUTE *route;
    route = (ROUTE *)malloc(sizeof(ROUTE));

    return route != NULL &&
        route_set_size(route, size) &&
        route_set_path(route, path)
    ? route
    : NULL;
}
int route_get_distance(ROUTE *route, DISTANCE_LIST *distance_list)
{
    if (route == NULL || distance_list == NULL)
        return -1;

    int size, i, route_distance = 0, partial_distance;

    PATH_NODE *current;

    for(current = path_node_get_next(path_get_head(route_get_path(route))); current != NULL; current = path_node_get_next(current))
    {   
        partial_distance = distance_list_node_get_distance_from_to(distance_list, path_node_get_key(path_node_get_prev(current)), path_node_get_key(current));

        if(partial_distance == -1) return -1;

        route_distance += partial_distance;
    }

    return route_distance;
}

ROUTE *route_get_next_permutation(ROUTE *route)
{
    PATH *path, *split_path;
    int j, larg_j;

    path = route_get_path(route);

    if (route == NULL)
        return NULL;

    j = route_get_larg_lgt(route);

    if (j == -1)
        return NULL;

    larg_j = route_get_larg_j_lg_i(route, j);
    path_swap(path, j, larg_j);
    split_path = path_split_after(path, larg_j);
    split_path = path_reverse(split_path);    

    PATH_NODE *current; 

    for(current = path_get_head(split_path); current != NULL; current = path_node_get_next(current))
        path_push(path, path_node_create(path_node_get_key(current)));
    
    return path != NULL && route_set_path(route, path) ? route : NULL;
};

int route_get_larg_j_lg_i(ROUTE *route, int i)
{
    int j = -1;
    PATH *path = route_get_path(route);
    PATH_NODE *current;

    for(current = path_get_head(path); current != NULL; current = path_node_get_next(current))
         if (path_node_get_key(current) > i) j = path_node_get_key(current);

    return j;
}

int route_get_larg_lgt (ROUTE *route) {
    PATH *path; 
    PATH_NODE *current;
    path = route_get_path(route);

    int x = -1;

    for (current = path_node_get_next(path_get_head(path)); current != NULL; current = path_node_get_next(current))
        x = path_node_get_key(current) > path_node_get_key(path_node_get_prev(current)) ?   path_node_get_key(path_node_get_prev(current))  : x;

    return x;
}

bool route_is_not_final_permutation(ROUTE *route)
{
    route != NULL && route_get_larg_lgt(route) == -1 ? false : true;
}

PATH *route_get_path(ROUTE *route)
{
    return route != NULL ? route->path : NULL;
}

int route_get_size(ROUTE *route) {
    if (route == NULL) return -1; 

    return route->size;
}
void route_print_best_route(DISTANCE_LIST *distance_list, int size) {
    ROUTE * route;

    if(distance_list == NULL) return; 

    route = route_get_best_route(distance_list, size);
    route_print(route, distance_list);
}

void route_print(ROUTE *route, DISTANCE_LIST *distance_list) {
    path_print(route_get_path(route));
    printf("\n Distancia: %d \n", route_get_distance(route, distance_list));
}

ROUTE *route_get_best_route(DISTANCE_LIST *distance_list, int size)
{
    int start = 3;

    if (distance_list == NULL)
        return NULL;

    int i, shortest_distance_so_far = INT_MAX;
    ROUTE *route, *best_route;
    PATH *path, *best_path;

    path = path_new();
    best_path = path_new();

    for(i = 1; i <= size; i++){
        path_push(path, path_node_create(i));
    }

    if (path == NULL)
        return NULL;

    route = route_new(size, path);
    best_route =  route_new(size, best_path);
    do
    {   
        if (route == NULL)
            break;

        int route_distance = route_get_distance(route, distance_list);

        if(route_distance == -1) continue;

        if (shortest_distance_so_far < route_distance)
            continue;


        shortest_distance_so_far = route_distance;
                
        PATH *best_path_so_far;
        best_path_so_far = path_new();
        
        PATH_NODE *current;
        
        for(current = path_get_head(route_get_path(route)); current != NULL; current = path_node_get_next(current))
            path_push(best_path_so_far, path_node_create(path_node_get_key(current)));
        
        route_set_path(best_route, best_path_so_far);

        route = route_get_next_permutation(route);
    } while (route_is_not_final_permutation(route));

    route_free(&route);

    return best_route != NULL ? best_route : NULL;
}

void route_free(ROUTE **route) {
    if (route == NULL) return;
    PATH_NODE  *current; 

    for(current = path_node_get_next(path_get_head(route_get_path(*route))); current != NULL; current = path_node_get_next(current)) {
        PATH_NODE *prev_node; 
        prev_node = path_node_get_prev(current);
        path_node_free(&prev_node);
        path_node_set_prev(current, NULL);
    }
    
    path_node_free(&current); 
    free(*route);
    route = NULL;
}
