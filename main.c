#include <stdio.h>
#include "tsp/tsp.h"
#include <time.h>

void main (int argc, char **argv){
    int start;
    time_t t1, t2, dt; 
    char* filename = "input_10.txt";

    t1 = time(NULL);
    tsp_print_shortest_route_from_file(filename);
    t2 = time(NULL);

    dt = difftime(t2,t1);

    printf("\n Tempo de execução: %ld \n", dt); 
       
    return;
}