#ifndef DISTANCE_LIST_H
#include <stdbool.h>

#define DISTANCE_LIST_H

#define TAM_MAX 10000 /*estimativa do tamanho máximo da distance_list*/
#define INT_MAX 2147483647

#include "distance_list_node/distance_list_node.h"

//definindo a struct distance_list_
typedef struct distance_list_ DISTANCE_LIST;

/*
 *Função para obter o tamanho da lista 
 * @param *distance_list  variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @return                retorna o tamanho da lista
 */
int distance_list_get_size(DISTANCE_LIST *distance_list);

/*
 *Função para retornar a distância entre duas cidades
 * @param *distance_list variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @param  from          variável do tipo inteiro que contém a cidade de partida
 * @param  to            variável do tipo inteiro que contém a cidade de chegada
 * @return               retorna a distância entre as cidades
 */
int distance_list_node_get_distance_from_to(DISTANCE_LIST *distance_list, int from, int to);

/*
 *Função para checar se a lista está cheia
 * @param *distance_list variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @return               retorna um booleano informando se a operação deu certo
 */
bool distance_list_is_full(DISTANCE_LIST *distance_list);

/*
 *Função para definir um node de início da lista
 * @param *distance_list      variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node a ser inserido
 * @return                    retorna uma variavel do tipo bool informando se a operação deu certo
 */
bool distance_list_set_head(DISTANCE_LIST *distance_list, DISTANCE_LIST_NODE *head);

/*
 *Função para definir um node de fim da lista
 * @param *distance_list      variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node a ser inserido
 * @return                    retorna uma variavel do tipo bool informando se a operação deu certo
 */                                                                ////@
bool distance_list_set_tail(DISTANCE_LIST *distance_list, DISTANCE_LIST_NODE *tail); 

/*
 *Função para checar se a lista está vazia
 * @param *distance_list  variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @return                retorna uma variavel do tipo bool informando se a operação deu certo
 */
bool distance_list_is_empty(DISTANCE_LIST *distance_list);

/*
 *Função para checar se a lista está cheia
 * @param *distance_list  variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @return                retorna uma variavel do tipo bool informando se a operação deu certo
 */
bool distance_list_is_full(DISTANCE_LIST *distance_list); 

/*
 *Função para adicionar um novo node ao começo da lista
 * @param *distance_list      variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um novo node
 * @return                    retorna um booleano informando se a operação deu certo
 */                                                                                          // @@
bool distance_list_unshift(DISTANCE_LIST *distance_list, DISTANCE_LIST_NODE *distance_list_node);

/*
 *Função para adicionar um novo node ao final da lista
 * @param *distance_list      variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node a ser adicionado
 * @return                    retorna um booleano informando se a operação deu certo
 */                                                 
bool distance_list_push(DISTANCE_LIST *distance_list, DISTANCE_LIST_NODE *distance_list_node);

/*
 *Função para adicionar um novo node antes de um node
 * @param *distance_list      variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node da lista
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um novo node
 * @return                    retorna um booleano informando se a operação deu certo
 */
bool distance_list_insert_before(DISTANCE_LIST *distance_list, DISTANCE_LIST_NODE *distance_list_node, DISTANCE_LIST_NODE *new_distance_list_node); 

/*
 *Função para adicionar um novo node a partir de um node
 * @param *distance_list      variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node da lista
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um novo node
 * @return                    retorna um booleano informando se a operação deu certo
 */
bool distance_list_insert_after(DISTANCE_LIST *distance_list, DISTANCE_LIST_NODE *distance_list_node, DISTANCE_LIST_NODE *new_distance_list_node);

/*
 *Função para limpar a list
 * @param **distance_list variável do tipo ponteiro duplo para DISTANCE_LIST que contém um lista de distâncias
 */
void distance_list_free(DISTANCE_LIST **distance_list);  

/*
 *Função para imprimir a distance_list
 * @param *distance_list variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 */                                        
void distance_list_print(DISTANCE_LIST *distance_list);          

/*
 *Função para deletar excluir um node de uma lista 
 * @param *distance_list      variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @param *distance_list_node variável do tipo ponteiro para DISTANCE_LIST_NODE que contém um node a ser apagado
 */
void distance_list_delete(DISTANCE_LIST *distance_list, DISTANCE_LIST_NODE *distance_list_node); 

/*
 *Função para deletar o node do começo da lista
 * @param *distance_list variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 */
void distance_list_delete_head(DISTANCE_LIST *distance_list);                                    

/*
 *Função para deletar o node do final da lista
 * @param *distance_list variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 */
void distance_list_delete_tail(DISTANCE_LIST *distance_list);                                    

/*
 *Função para obter o node do início da lista
 * @param *distance_list  variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @return                retorna uma variavel do tipo DISTANCE_LIST_NODE
 */
DISTANCE_LIST_NODE *distance_list_get_head(DISTANCE_LIST *distance_list); 

/*
 *Função para obter o node do fim da lista
 * @param *distance_list variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @return               retorna uma variavel do tipo DISTANCE_LIST_NODE
 */
DISTANCE_LIST_NODE *distance_list_get_tail(DISTANCE_LIST *distance_list);                             

/*
 *Função para encontrar um node na lista num intervalo entre um node de partida e um node de fim
 * @param *distance_list variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @param from           variável do tipo inteiro que contém um node de partida
 * @param to             variável do tipo inteiro que contém um node de fim
 * @return               retorna o node procurado
 */
DISTANCE_LIST_NODE *distance_list_search_with_from_to(DISTANCE_LIST *distance_list, int from, int to); // @@

/*
 *Função para encontrar um node na lista 
 * @param *distance_list  variável do tipo ponteiro para DISTANCE_LIST que contém um lista de distâncias
 * @param key             variável do tipo inteiro que contém uma chave da lista
 * @return                retorna o node procurado
 */
DISTANCE_LIST_NODE *distance_list_search(DISTANCE_LIST *distance_list, int key);                       

/*
 *Função para criar uma lista
 * @return  retorna uma variável do tipo DISTANCE_LIST com a lista criada
 */
DISTANCE_LIST *distance_list_new();

#endif