#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include "tsp.h"
#include "distance_list/distance_list.h"
#include "brute_force/brute_force.h"
#include "../path/path.h"

#define LOG true

DISTANCE_LIST *tsp_read_distance_file (char* filename, int * size)
{
    DISTANCE_LIST *distance_list = distance_list_new();

    if(distance_list == NULL) return NULL; 

    FILE* file = fopen(filename, "r");
    int i = 0;

    fscanf(file, "%d", size);     

    while(!feof (file)){ 
        int from, to, distance;

        fscanf(file,"%d %d %d", &from, &to, &distance);

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

void tsp_solve_brute_force(char* filename) {
    int start;
    long clock_start, clock_end;
    struct timeval timecheck;
    DISTANCE_LIST *distance_list = distance_list_new();
    PATH* path;
    
    printf("\nEntre com cidade de partida: \n");
    scanf("%d", &start);

    int size = 0;
    distance_list = tsp_read_distance_file (filename, &size);
    
    gettimeofday(&timecheck, NULL);
    clock_start = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
    path = brute_force(distance_list, size, start);
    gettimeofday(&timecheck, NULL);
    clock_end = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;

    long milliseconds = (clock_end - clock_start);

    path_print(path);

    if (LOG == true) {
        printf("\n DISTANCIA MELHOR ROTA:  %d \n", path_calculate_distance(path, distance_list, start));
        printf("\n TEMPO DE EXECUÇÃO BRUTE FORCE:  %f s \n", (float)milliseconds/1000);
    }
}



