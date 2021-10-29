#ifndef DISTANCE_LIST_NODE_H
#define DISTANCE_LIST_NODE_H
#include <stdbool.h>

//definindo a struct distance_list_node
typedef struct distance_list_node_ DISTANCE_LIST_NODE;

/*
 *Função para obter a chave de um node
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node
 * @return                    retorna uma variavel do tipo inteiro contendo a chave do node 
 */
int distance_list_node_get_key(DISTANCE_LIST_NODE *distance_list_node);

/*
 *Função para definir a cidade de partida de um node 
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node
 * @return                    retorna uma variavel do tipo inteiro contendo a chave da cidade de partida 
 */
int distance_list_node_get_from(DISTANCE_LIST_NODE *distance_list_node);

/*
 *Função para definir a cidade de destino de um node
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node
 * @return                    retorna uma variavel do tipo inteiro contendo a chave da cidade de destino 
 */
int distance_list_node_get_to(DISTANCE_LIST_NODE *distance_list_node);

/*
 *Função para definir a distancia contida em um node
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node
 * @return                    retorna uma variavel do tipo inteiro contendo a distancia buscada
 */
int distance_list_node_get_distance(DISTANCE_LIST_NODE *distance_list_node);

/*
 *Função para limpar um node
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node
 * @return                    retorna uma variavel do tipo bool informando se a operação deu certo
 */
bool distance_list_node_free(DISTANCE_LIST_NODE **distance_list_node);

/*
 *Função para definir a chave de um node
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node
 * @param key                 variável do tipo inteiro que contém uma chave da lista 
 * @return                    retorna uma variavel do tipo bool informando se a operação deu certo
 */
bool distance_list_node_set_key(DISTANCE_LIST_NODE *distance_list_node, int key);

/*
 *Função para definir a chave da cidade de partida de um node
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node
 * @param  from               variável do tipo inteiro que contém a cidade de partida
 * @return                    retorna uma variavel do tipo bool informando se a operação deu certo
 */
bool distance_list_node_set_from(DISTANCE_LIST_NODE *distance_list_node, int from);

/*
 *Função para definir um node de início da lista
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node a ser inserido
 * @param  to                 variável do tipo inteiro que contém a cidade de chegada
 * @return                    retorna uma variavel do tipo bool informando se a operação deu certo
 */
bool distance_list_node_set_to(DISTANCE_LIST_NODE *distance_list_node, int to);

/*
 *Função para definir a distancia de um node
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node
 * @param  distance           variável do tipo inteiro que contém a distancia de um node
 * @return                    retorna uma variavel do tipo bool informando se a operação deu certo
 */
bool distance_list_node_set_distance(DISTANCE_LIST_NODE *distance_list_node, int distance);

/*
 *Função para definir o próximo node de um node dado
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node 
 * @param *next               variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node 
 * @return                    retorna uma variavel do tipo bool informando se a operação deu certo
 */
bool distance_list_node_set_next(DISTANCE_LIST_NODE *distance_list_node, DISTANCE_LIST_NODE *next);

/*
 *Função para definir o node anterior de um node dado
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node 
 * @param *prev               variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node 
 * @return                    retorna uma variavel do tipo bool informando se a operação deu certo
 */
bool distance_list_node_set_prev(DISTANCE_LIST_NODE *distance_list_node, DISTANCE_LIST_NODE *prev);

/*
 *Função para deletar a chave de um node
 * @param **distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node 
 * @return                     retorna uma variavel do tipo bool informando se a operação deu certo
 */
bool distance_list_node_delete_key(DISTANCE_LIST_NODE **distance_list_node);

/*
 *Função para imprimir um node
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node 
 */
void distance_list_node_print(DISTANCE_LIST_NODE *distance_list_node);


/*
 *Função para criar o nó de uma lista
 * @param key                 variável do tipo inteiro que contém uma chave da lista 
 * @return                    retorna uma variavel do tipo DISTANCE_LIST_NODE contendo o no criado
 */
DISTANCE_LIST_NODE *distance_list_node_create(int key);

/*
 *Função para obter o node anterior a um node dado
 * @param **distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node 
 * @return                     retorna uma variavel do tipo DISTANCE_LIST_NODE com o node buscado
 */
DISTANCE_LIST_NODE *distance_list_node_get_prev(DISTANCE_LIST_NODE *distance_list_node);

/*
 *Função para obter o node posterior a um node dado
 * @param **distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node 
 * @return                     retorna uma variavel do tipo DISTANCE_LIST_NODE com o node buscado
 */
DISTANCE_LIST_NODE *distance_list_node_get_next(DISTANCE_LIST_NODE *distance_list_node);

#endif