#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/*
#include "route.h"
#include "../path/path.h"
#include "../path/path_node/path_node.h"
#include "../tsp/distance_list/distance_list.h"

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

bool route_set_path(ROUTE *route, int *path)
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
        return NULL;

    int size, i, route_distance = 0;
    size = path_get_size(route_get_path(route));

    for (i = 1; i <= size; i++)
    {
        route_distance += distance_list_node_get_distance_from_to(distance_list, i - 1, i);
    }
    route_distance += distance_list_node_get_distance_from_to(distance_list, 1, size);

    return route_distance;
}

ROUTE *route_get_next_permutation(ROUTE *route)
{
    PATH *path, *split_path;
    int j, larg_j;

    if (route == NULL)
        return NULL;

    j = route_get_larg_j_lg_i(route, 1);

    if (j == -1)
        return NULL;

    larg_j = route_get_larg_j_lg_i(route, j);

    split_path = path_split_after(path, j);
    path_reverse(split_path);
    path_concat(path, split_path);

    return path != NULL && route_set_path(route, path) ? route : NULL;
};

int route_get_larg_j_lg_i(ROUTE *route, int i)
{
    int i, j = -1, size = path_get_size(route_get_path(route));
    PATH *path = route_get_path(route);

    for (i = i; i < size; i++)
    {
        PATH_NODE  *path_node_a, *path_node_b;

        path_node_a = path_search(i - 1, path);
        path_node_b = path_search(i, path);

        if (path_node_get_key(path_node_a) < path_node_get_key(path_node_b))
        {
            j = i - 1;
        }
    }

    return j;
}

bool route_is_not_tail_permutation(ROUTE *route)
{
    route != NULL &&route_get_largest_largest(route) == -1 ? false : true;
}

PATH *route_get_path(ROUTE *route)
{
    return route != NULL ? route->path : NULL;
}

int route_get_size(ROUTE *route) {
    if (route == NULL) return NULL; 

    return route->size;
}

ROUTE *route_get_best_route(DISTANCE_LIST *distance_list)
{
    if (distance_list == NULL)
        return NULL;

    int i, size, shortest_distance_so_far = INT_MAX;
    ROUTE *route;
    PATH *path;

    size = distance_list_get_size(distance_list);
    path = path_new();

    for(i = 1; i <= size; i++){
        PATH_NODE  *path_node;

        path_node = path_node_create(i);

        path_push(path, path_node);
    }

    if (path == NULL)
        return NULL;

    route = route_new(size, path);

    do
    {
        route = route_get_next_permutation(route);
        if (route == NULL)
            break;

        int route_distance = route_get_distance(route, distance_list);

        if (
            shortest_distance_so_far > route_distance ||
            path_node_get_key(path_get_tail(route_get_path(route))) == route_get_size(route))
            continue;

        shortest_distance_so_far = route_distance;
        path_copy(route_get_path(route), path);

    } while (route_is_not_tail_permutation(route));

    return route != NULL ? route : NULL;
}

void route_free(ROUTE **route) {
    if (route == NULL) return;
    PATH_NODE  *current; 

    for(current = path_node_get_next(path_get_head(route_get_path(*route))); current != NULL; current = path_node_get_next(current)) {
        path_node_free(path_node_get_prev(current));
        path_node_set_prev(current, NULL);
    }
    
    path_node_free(current); 
    free(*route);
    route = NULL;
}
*/