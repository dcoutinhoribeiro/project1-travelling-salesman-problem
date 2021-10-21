#include <stdlib.h>
#include <stdio.h>
#include "tsp.h"
#include "distance_list/distance_list.h"
#include "../route/route.h"

DISTANCE_LIST *tsp_read_distance_file (char* filename)
{
    DISTANCE_LIST *distance_list = distance_list_new();

    if(distance_list == NULL) return NULL; 

    FILE* file = fopen (filename, "r");
    int i = 0, size = 0;

    size = fscanf (file, "%d", &i);     

    while(!!feof (file)){ 
        int from, to, distance;

        fscanf("%d %d %d", &from, &to, &distance);

        DISTANCE_LIST_NODE *distance_list_node;

        distance_list_node = distance_list_node_create(i);

        distance_list_node_set_from(distance_list_node, from);
        distance_list_node_set_to(distance_list_node, to);
        distance_list_node_set_distance(distance_list_node, distance);

        distance_list_push(distance_list, distance_list_node);

        i++;
    }  

    fclose (file);     

    return distance_list;  
}

int tsp_get_shortest_route_from_file(char* filename) {
    DISTANCE_LIST *distance_list = distance_list_new();

    distance_list = tsp_read_distance_file (filename);
    distance_list_print(distance_list);


}