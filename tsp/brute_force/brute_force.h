#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H
#include <stdbool.h>
#include "../distance_list/distance_list.h"
#include "../../path/path.h"

/*
 *Função para resolver o problema do caixeiro viajante pelo método de força bruta 
 * @param *distance_list variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @param  size          variável do tipo inteiro que contém o número de cidades
 * @param  start         variável do tipo inteiro que contém a cidade de início
 * @return               retorna uma variável do tipo PATH com o melhor caminho
 */
PATH *brute_force(DISTANCE_LIST *distance_list, int size, int start);

#endif
