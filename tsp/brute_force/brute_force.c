#include <stdlib.h>
#include <stdio.h>

#include "brute_force.h"
#include "../../path/path.h"
#include "../../path/path_node/path_node.h"
#include "../distance_list/distance_list.h"

PATH *brute_force(DISTANCE_LIST *distance_list, int size, int start) {
    if(distance_list == NULL) return NULL;

    PATH *current_path, *best_path ;

    current_path = path_new();
    best_path = path_new();

    if(current_path == NULL || best_path == NULL) return NULL;

    path_populate(current_path, size, start);
    path_copy_to(best_path, current_path);

    int shortest_distance_so_far = path_calculate_distance(current_path, distance_list, start);

    printf("\n⚙️  Trabalhando...  \n");

    if(size >= 6) printf("⏳ Isto pode levar uns minutinhos ⏳ \n");

    while (current_path != NULL) {
        current_path = path_get_next_permutation(current_path);
        
        int route_distance = path_calculate_distance(current_path, distance_list, start);
        if(
            route_distance == NOT_FOUND || 
            shortest_distance_so_far < route_distance
        )
            continue;

        shortest_distance_so_far = route_distance;
        path_copy_to(best_path, current_path);
    } 

    return best_path;
}