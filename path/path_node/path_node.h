#ifndef PATH_NODE_H
#define PATH_NODE_H
#define NOT_FOUND -1
#include <stdbool.h>

//definindo a struct path_node
typedef struct path_node_ PATH_NODE;

/*
 *Função para retornar a chave de uma cidade
 * @param *path_node     variável do tipo ponteiro para PATH_NODE que contém um nó
 * @return               retorna a chave da cidade
 */
int path_node_get_key(PATH_NODE *path_node);

/*
 *Função para liberar um no
 * @param **path_node  variável do tipo ponteiro duplo para PATH_NODE que contém o endereço de um nó
 * @return             retorna um booleano informando se a operação deu certo
 */
bool path_node_free(PATH_NODE **path_node);

/*
 *Função para definir a chave de um nó
 * @param *path_node     variável do tipo ponteiro para PATH_NODE que contém um nó
 * @param key            variável do tipo inteiro que contém a chave do nó
 * @return               retorna um booleano informando se a operação deu certo
 */
bool path_node_set_key(PATH_NODE *path_node, int key);

/*
 *Função para definir o próximo nó de um nó dado
 * @param *path_node     variável do tipo ponteiro para PATH_NODE que contém um nó
 * @param *next          variável do tipo ponteiro para PATH_NODE que contém um nó seguinte
 * @return               retorna um booleano informando se a operação deu certo
 */
bool path_node_set_next(PATH_NODE *path_node, PATH_NODE *next);

/*
 *Função para definir o nó anterior de um nó dado
 * @param *path_node     variável do tipo ponteiro para PATH_NODE que contém um nó
 * @param *prev          variável do tipo ponteiro para PATH_NODE que contém o nó anterior
 * @return               retorna um booleano informando se a operação deu certo
 */
bool path_node_set_prev(PATH_NODE *path_node, PATH_NODE *prev);

/*
 *Função para imprimir um nó dado
 * @param *path_node     variável do tipo ponteiro para PATH_NODE que contém um nó
 */
void path_node_print(PATH_NODE *path_node);

/*
 *Função para criar um nó
 * @param key    variável do tipo inteiro que contem a chave do nó a ser criado
 * @return       retorna uma variável do tipo PATH_NODE com o nó criado
 */
PATH_NODE *path_node_create(int key);

/*
 *Função para obter o nó anterior ao nó dado
 * @param *path_node     variável do tipo ponteiro para PATH_NODE que contém um nó
 * @return               retorna uma variável do tipo PATH_NODE com o nó procurado
 */
PATH_NODE *path_node_get_prev(PATH_NODE *path_node);

/*
 *Função para obter o nó seguinte ao nó dado
 * @param *path_node     variável do tipo ponteiro para PATH_NODE que contém um nó
 * @return               retorna uma variável do tipo PATH_NODE com o nó procurado
 */
PATH_NODE *path_node_get_next(PATH_NODE *path_node);
#endif