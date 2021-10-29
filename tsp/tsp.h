#ifndef TSP_H
#define TSP_H
#include <stdbool.h>
#include "distance_list/distance_list.h"

/*
 *Função para resolver o problema do caixeiro viajante pelo método de força bruta
 * @param *filename variável do tipo ponteiro para char que contém o nome do arquivo
 */
void tsp_solve_brute_force(char *filename, bool lflag);

/*
 *Função para ler um arquivo contendo as cidades e as repectivas distâncias entre elas
 * @param *filename variável do tipo ponteiro para char que contém o nome do arquivo
 * @param  size     variável do tipo ponteiro para inteiro que contém o número de cidades
 * @return               retorna a nova distance_list
 */
DISTANCE_LIST *tsp_read_distance_file(char *filename, int *size);

#endif
