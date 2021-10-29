#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include "tsp.h"
#include "distance_list/distance_list.h"
#include "brute_force/brute_force.h"
#include "../path/path.h"

DISTANCE_LIST *tsp_read_distance_file (char* filename, int* size)
{
    DISTANCE_LIST *distance_list = distance_list_new();

    if(distance_list == NULL) return NULL; 

    FILE* file = fopen(filename, "r");
    int i = 0;

    if (file == NULL) return NULL;

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

void tsp_solve_brute_force(char* filename, bool lflag) {
    int start = -1;
    long clock_start, clock_end;
    struct timeval timecheck;
    DISTANCE_LIST *distance_list = distance_list_new();
    PATH* path;
    

    int size = INT_MAX;
    distance_list = tsp_read_distance_file (filename, &size);

    if(distance_list == NULL){
        printf("\nFilename inválido 😔\n");
        return;
    }
     
    do {
        printf("\nEntre com cidade de partida: \n");
        scanf("%d", &start);
    } while(start < 1 || start > size);

    gettimeofday(&timecheck, NULL);
    clock_start = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
    path = brute_force(distance_list, size, start);
    gettimeofday(&timecheck, NULL);
    clock_end = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;

    long milliseconds = (clock_end - clock_start);

    printf("\nO melhor caminho é (a ordem dos dados é cidade de origem, rota e distancia): \n \n");

    path_print_with_start(path, distance_list, start);

    if (lflag == true) {
        printf("\nTEMPO DE EXECUÇÃO BRUTE FORCE:  %f s \n", (float)milliseconds/1000);
    }
}



