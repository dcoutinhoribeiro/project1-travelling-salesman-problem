#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include "tsp/tsp.h"

void main(int argc, char **argv)
{
    int start, i, c;
    char *filename = NULL;

    while ((c = getopt(argc, argv, "f:a")) != -1)
    {
        switch (c)
        {
            case 'f':
                filename = optarg;
                break;
            case '?':
                if (optopt == 'f')
                    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint(optopt))
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf(stderr,
                            "Unknown option character `\\x%x'.\n",
                            optopt);
                return;
            default:
                abort();
        }
    }

    //chamando a função que resolve o problema do caixeiro viajante
    tsp_solve_brute_force(filename);

    return;
}