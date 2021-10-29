#ifndef PATH_H
#include <stdbool.h>

#define PATH_H

#define TAM_MAX_PATH 13 /*estimativa do tamanho máximo da path*/
#define INT_MAX 2147483647

#include "path_node/path_node.h"
#include "../tsp/distance_list/distance_list.h"

//definindo a struct path_
typedef struct path_ PATH;

/*
 *Função para retornar o tamanho de um path
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @return        retorna um inteiro com o tamanho do path
 */
int path_get_size(PATH *path);

/*
 *Função para calcular a distância total de um path (corresponde a soma das distâncias entre cada cidade) 
 * @param  *path          uma variavel ponteiro de PATH com um caminho possível
 * @param  *distance_list uma variavel ponteiro de DISTANCE_LIST com uma lista contendo as distâncias entre cada cidade do path
 * @param   start         uma variavel do tipo inteiro que informa a partir de qual cidade deve-se calcular a distância total
 * @return                retorna a distância calculada
 */
int path_calculate_distance(PATH *path, DISTANCE_LIST *distance_list, int start);

/*
 *Função para alocar uma head a um path
 * @param  *path uma variavel ponteiro de PATH com um path qualquer
 * @param  *head uma variavel ponteir de PATH_NODE  com o path_node que sera o começo do path
 * @return       retorna um bool informando se a operacao deu certo
 */
bool path_set_head(PATH *path, PATH_NODE *head); 

/*
 *Função para alocar uma tail a um path
 * @param  *path uma variavel ponteiro de PATH com um path qualquer
 * @param  *tail uma variavel ponteir de PATH_NODE  com o path_node que sera o fim do path
 * @return       retorna um bool informando se a operacao deu certo
 */
bool path_set_tail(PATH *path, PATH_NODE *tail); 

/*
 *Função para colocar um PATH_NODE como primeiro elemento da lista PATH 
 * @param  *path        uma variavel ponteiro de PATH com um caminho possível
 * @param  *path_node   uma variavel do tipo PATH_NODE que contem um novo path_node
 * @return              retorna uma variável do tipo bool informando se a operação deu certo 
 */
bool path_unshift(PATH *path, PATH_NODE *path_node);                                 

/*
 *Função para inserir um path node ao path
 * @param  *path      uma variavel ponteiro de PATH com um caminho possível
 * @param  *path_node uma variavel ponteiro de PATH_NODE com o path_node que será inserido
 * @retun             um booleano informando se a operação deu certo
 */
bool path_push(PATH *path, PATH_NODE *path_node);                                    

/*
 *Função para inserir um path_node antes de outro path_node informado
 * @param  *path          uma variavel ponteiro de PATH com um caminho possível
 * @param  *path_node     uma variavel ponteiro de PATH_NODE com o path_node que será usado como ponto de chegada
 * @param  *new_path_node uma variavel do tipo PATH_NODE que contém o novo path_node a ser inserido
 * @return                retorna uma variavel do tipo bool informando se a operação deu certo
 */
bool path_insert_before(PATH *path, PATH_NODE *path_node, PATH_NODE *new_path_node); 

/*
 *Função para inserir um path_node a partir de outro path_node informado
 * @param  *path          uma variavel ponteiro de PATH com um caminho possível
 * @param  *path_node     uma variavel ponteiro de PATH_NODE com o path que será usado como ponto de partida
 * @param  *new_path_node uma variavel do tipo PATH_NODE que contém o novo path_node a ser inserido
 * @return                retorna uma variavel do tipo bool informando se a operação deu certo
 */
bool path_insert_after(PATH *path, PATH_NODE *path_node, PATH_NODE *new_path_node);

/*
 *Função para checar se um path esta vazio
 * @param  *path uma variavel ponteiro de PATH com um path qualquer
 * @return       retorna um bool informando se a operacao deu certo
 */
bool path_is_empty(PATH *path); 

/*
 *Função para checar se uma caminho está cheio
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @retun         um booleano informando se a operação deu certo
 */
bool path_is_full(PATH *path);  

/*
 *Função para trocar de posição dois path_nodes do path
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @param   i     uma variavel do tipo inteiro que contem a chave do path a ser trocado de posição
 * @param   j     uma variavel do tipo inteiro que contem a chave do path a ser trocado de posição
 */
void path_swap(PATH *path, int i, int j); 

/*
 *Função para apagar um PATH
 * @param  **path  uma variavel ponteiro duplo de PATH com o PATH original
 */
void path_free(PATH **path);             

/*
 *Função para imprimir um PATH com um cidade de início
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @param   start uma variavel do tipo inteiro que contém a chave da cidade de início 
 */
void path_print_with_start(PATH *path, DISTANCE_LIST *distance_list, int start);

/*
 *Função para imprimir um PATH
 * @param *path       uma variavel ponteiro de PATH com um caminho possível
 * @param *path_node  uma variavel ponteiro de PATH_NODE  que contém o número de uma cidade   
 * 
 */
void path_print(PATH *path);                         

/*
 *Função para popular um PATH com valores aleatórios 
 * @param  *path       uma variavel ponteiro de PATH com um caminho possível
 * @param   size       uma variavel do tipo inteiro com o tamanho do path a ser criado
 * @param   start      uma variavel do tipo inteiro 
 * @param   is_random  uma variavel do tipo bool
 */
void path_populate(PATH *path, int size, int start);

/*
 *Função para copiar um PATH  
 * @param  *path         uma variavel ponteiro de PATH com um caminho possível
 * @param  *source_path  uma variavel ponteiro de PATH com o path a ser copiado 
 */
void path_copy_to(PATH *path, PATH *source_path);

/*
 *Função para apagar o primeiro PATH_NODE  de um PATH
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @return        retorna o PATH_NODE  que estava no comeco do PATH 
 */
void path_delete_head(PATH *path);                 

/*
 *Função para apagar o ultimo PATH_NODE  de um PATH
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @return        retorna o PATH_NODE  que estava no fim do PATH 
 */
void path_delete_tail(PATH *path);                 

/*
 *Função que retorna o path_node do comeco de um path
 * @param  *path uma variavel ponteiro de PATH com um path qualquer
 * @return       retorna um path_node que e comeco do path
 */
PATH_NODE *path_get_head(PATH *path);        

/*
 *Função que retorna o path_node do fim de um path
 * @param  *path uma variavel ponteiro de PATH com um path qualquer
 * @return       retorna um path_node que e fim do path
 */
PATH_NODE *path_get_tail(PATH *path);   

/*
 *Função para procurar por uma key no PATH
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @param   key   uma variavel inteira com o valor da key (cidade)
 * @return        retorna o PATH_NODE  com a key procurada 
 */
PATH_NODE *path_search(PATH *path, int key);

/*
 *Função para uma nova permutação de um path de acordo com a ordem lexicográfica 
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @return        retorna a próxima permutação do path
 */
PATH *path_get_next_permutation(PATH *route);

/*
 *Função para criar um path
 *@return retorna o path criado e retornado
 */
PATH *path_new();

#endif