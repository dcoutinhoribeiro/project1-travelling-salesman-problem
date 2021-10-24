#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "path.h"
#include "path_node/path_node.h"
#include "../tsp/distance_list/distance_list.h"

struct path_
{
    PATH_NODE  *head;
    PATH_NODE  *tail;
};

bool path_unshift(PATH *path, PATH_NODE  *path_node)
{
    if (path == NULL || path_node == NULL || path_is_full(path))
        return false;

    if(path_get_head(path) == NULL) {
        path_set_head(path, path_node);
        path_set_tail(path, path_node); 
        path_node_set_next(path_node, NULL);
        path_node_set_prev(path_node, NULL);
        
        return true;
    } else 
        return path_insert_before(path, path_get_head(path), path_node);
}

void path_copy_to(PATH* path, PATH *source_path) {
    if (path == NULL || source_path == NULL) return; 

    PATH_NODE *current;

    PATH *new_path;
    
    path_free(&path);

    new_path = path_new();

    for(current = path_get_head(source_path); current != NULL; current = path_node_get_next(current)) 
        path_push(new_path, path_node_create(path_node_get_key(current)));

    path = new_path;
}

void path_populate(PATH *path, int size, int start, bool is_random) {
    int i;
    if (is_random == false) {
        for(i = 1; i <= size; i++) {
            if(i != start) {
                path_push(path, path_node_create(i));
            }
        }
    } else {
        while(path_get_size(path) != size) {
             int random = (rand() % size) + 1; //gera x aleatorio tq x pertence a [1,size]
            
            if(path_search(path, random) == NULL) 
                path_push(path, path_node_create(random));
        } 
    }
}

PATH *path_get_next_permutation(PATH *path)
{
    PATH_NODE *current;
    PATH *aux_path;
    int x = NOT_FOUND, y = NOT_FOUND, i;
  
    aux_path = path_new();

    for(current = path_node_get_next(path_get_head(path)); current != NULL; current = path_node_get_next(current))
        if(path_node_get_key(current) > path_node_get_key(path_node_get_prev(current))) x = path_node_get_key(path_node_get_prev(current));

    if (x == NOT_FOUND) return NULL;

    for(current = path_get_head(path); current != NULL; current = path_node_get_next(current))
        if(path_node_get_key(current) > x) y = path_node_get_key(current);

    path_swap(path, x, y);
    
    for(current = path_node_get_next(path_search(path, y)); current != NULL; current = path_node_get_next(current)) 
        path_unshift(aux_path, path_node_create(path_node_get_key(current)));
   
    for(current = path_get_head(aux_path); current != NULL; current = path_node_get_next(current)){
        path_delete(path, path_search(path, path_node_get_key(current)));
        path_push(path, path_node_create(path_node_get_key(current)));
    }

    path_free(&aux_path);

    return path;
};


int path_calculate_distance(PATH *path, DISTANCE_LIST *distance_list, int start)
{
    if (path == NULL || distance_list == NULL)
        return NOT_FOUND;

    int size, i, head_to_tail = 0, partial_distance;
    int start_to_head = distance_list_node_get_distance_from_to(distance_list, path_node_get_key(path_get_head(path)), start);
    int tail_to_start = distance_list_node_get_distance_from_to(distance_list, path_node_get_key(path_get_tail(path)), start);
    
    if(start_to_head == NOT_FOUND || tail_to_start == NOT_FOUND) return NOT_FOUND;

    PATH_NODE *current;

    for(current = path_node_get_next(path_get_head(path)); current != NULL; current = path_node_get_next(current))
    {   
        partial_distance = distance_list_node_get_distance_from_to(distance_list, path_node_get_key(path_node_get_prev(current)), path_node_get_key(current));

        if(partial_distance == -1) return NOT_FOUND;

        head_to_tail += partial_distance;
    }
 
    return start_to_head + head_to_tail + tail_to_start;
}




bool path_insert_after(PATH *path, PATH_NODE *path_node, PATH_NODE *new_path_node) {
    if (path == NULL || path_node == NULL || new_path_node == NULL) return false;

    path_node_set_prev(new_path_node, path_node);

    if(path_node_get_next(path_node) == NULL) {
        path_node_set_next(new_path_node, NULL);
        path_set_tail(path, new_path_node);
    } else {
        path_node_set_next(new_path_node, path_node_get_next(path_node));
        path_node_set_prev(path_node_get_next(path_node), new_path_node);
    }
    
    path_node_set_next(path_node, new_path_node);

    return true;
}

bool path_insert_before(PATH *path, PATH_NODE *path_node, PATH_NODE *new_path_node) {
    if (path == NULL || path_node == NULL || new_path_node == NULL) return false;

    path_node_set_next(new_path_node, path_node);

    if(path_node_get_prev(path_node) == NULL) {
        path_node_set_prev(new_path_node, NULL);
        path_set_head(path, new_path_node);
    } else {
        path_node_set_prev(new_path_node, path_node_get_prev(path_node));
        path_node_set_next(path_node_get_prev(path_node), new_path_node);
    }
    
    path_node_set_prev(path_node, new_path_node);

    return true;
}

/*
 *Função para trocar um PATH_NODE  de um PATH por outro PATH_NODE 
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @param   int   uma variavel do tipo inteiro que contem a key de PATH_NODE 
 * @param   int   uma variavel do tipo inteiro que contem a key de PATH_NODE 
 */

/*
 *Função para imprimir um PATH
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @param *path_node  uma variavel ponteiro de PATH_NODE  que contém o número de uma cidade   
 * 
 */
void path_print(PATH *path) {
    if (path == NULL) return;

    PATH_NODE  *current;

    printf ("\n");

    for(current = path_get_head(path); current != NULL; current = path_node_get_next(current)) {
        if(current == path_get_head(path)) 
            printf("%d", path_node_get_key(current));
        else 
            printf (" -> %d", path_node_get_key(current)); 
    }

    printf ("\n");

}
void path_print_with_start(PATH *path, int start) {
    if (path == NULL) return;

    PATH_NODE  *current;

    printf ("\n%d", start);

    for(current = path_get_head(path); current != NULL; current = path_node_get_next(current)) printf (" -> %d", path_node_get_key(current)); 

    printf (" -> %d \n", start);

}

/*
 *Função para checar se uma caminho está cheio
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @retun  um booleano informando se a operação deu certo
 */

bool path_is_full(PATH *path)
{
    if (path == NULL)
        return true;

    return path_get_size(path) == TAM_MAX_PATH;
};

bool path_push(PATH *path, PATH_NODE  *path_node)
{
    if (path == NULL || path_node == NULL || path_is_full(path))
        return false;

    if(path_get_tail(path) == NULL) 
        return path_unshift(path, path_node);
    else 
        return path_insert_after(path, path_get_tail(path), path_node);
}

/*
 *Função para apagar um PATH
 * @param  **path  uma variavel ponteiro duplo de PATH com o PATH original
 */
void path_free(PATH **path) {
    if(*path == NULL) return ;
        free(*path);
    *path = NULL; 
}


void path_swap(PATH *path, int i, int j)
{
    if (path == NULL) return;

    PATH_NODE  *item_a, *item_b;

    item_a = path_search(path, i);
    item_b = path_search(path, j);

    if (item_a == NULL || item_b == NULL)
        return;

   path_insert_after(path, item_a, path_node_create(INT_MAX - j));
   path_delete(path,item_a);
   path_insert_after(path, item_b, path_node_create(i));
   path_delete(path,item_b);
   path_node_set_key(path_search(path, INT_MAX - j), j);
}

/*
 *Função para apagar o primeiro PATH_NODE  de um PATH
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @return retorna o PATH_NODE  que estava no comeco do PATH 
 */
void path_delete_head(PATH *path)
{
    if (path == NULL || path_is_empty(path))
        return;

    path_delete(path, path_get_head(path));
}

/*
 *Função para apagar o ultimo PATH_NODE  de um PATH
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @return retorna o PATH_NODE  que estava no fim do PATH 
 */
void  path_delete_tail(PATH *path)
{
   if (path == NULL || path_is_empty(path))
        return;

    path_delete(path, path_get_tail(path));
}

/*
 *Função para procurar por uma key no PATH
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @param   key   uma variavel inteira com o valor da key (cidade)
 * @return retorna o PATH_NODE  com a key procurada 
 */
PATH_NODE  *path_search(PATH *path, int key)
{
    PATH_NODE  *found = NULL, *current;

    if (path == NULL)
        return NULL;

    for (current = path_get_head(path); current != NULL; current = path_node_get_next(current))
        if (path_node_get_key(current) == key)
            found = current;

    return found;
}


void  path_delete(PATH *path, PATH_NODE *path_node)
{
    if (path == NULL || path_is_empty(path))
        return;

    if(path_node_get_prev(path_node) == NULL)
        path_set_head(path, path_node_get_next(path_node)); 
    else 
        path_node_set_next(path_node_get_prev(path_node), path_node_get_next(path_node));

    if(path_node_get_next(path_node) == NULL)
            path_set_tail(path, path_node_get_prev(path_node)); 
    else 
        path_node_set_prev(path_node_get_next(path_node), path_node_get_prev(path_node));   
}

/*
 *Função para retornar o tamanho de um path
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @return retorna um inteiro com o tamanho do path
 */
int path_get_size(PATH *path)
{
    if (path == NULL)
        return -1;

    int size = 0;

    PATH_NODE  *current;

    for (current = path_get_head(path); current != NULL; current = path_node_get_next(current))
    {
        size++;
    }

    return size;
}

/*
 *Função para alocar uma head a um path
 * @param  *path uma variavel ponteiro de PATH com um path qualquer
 * @param  *head uma variavel ponteir de PATH_NODE  com o path_node que sera o começo do path
 * @return um bool informando se a operacao deu certo
 */
bool path_set_head(PATH *path, PATH_NODE  *head)
{
    if (path != NULL)
    {
        path->head = head;
        return true;
    }
    return false;
}

/*
 *Função para alocar uma tail a um path
 * @param  *path uma variavel ponteiro de PATH com um path qualquer
 * @param  *tail uma variavel ponteir de PATH_NODE  com o path_node que sera o fim do path
 * @return um bool informando se a operacao deu certo
 */
bool path_set_tail(PATH *path, PATH_NODE  *tail)
{
    if (path != NULL)
    {
        path->tail = tail;
        return true;
    }
    return false;
}

/*
 *Função que retorna o path_node do comeco de um path
 * @param  *path uma variavel ponteiro de PATH com um path qualquer
 * @return um path_node que e comeco do path
 */
PATH_NODE  *path_get_head(PATH *path)
{
    return path != NULL ? path->head : NULL;
}

/*
 *Função que retorna o path_node do fim de um path
 * @param  *path uma variavel ponteiro de PATH com um path qualquer
 * @return um path_node que e fim do path
 */
PATH_NODE  *path_get_tail(PATH *path)
{
    return path != NULL ? path->tail : NULL;
}

/*
 *Função para checar se um path esta vazio
 * @param  *path uma variavel ponteiro de PATH com um path qualquer
 * @return um bool informando se a operacao deu certo
 */
bool path_is_empty(PATH *path)
{
    return path_get_head(path) == NULL || path_get_tail(path) == NULL;
}

/*
 *Função para criar um path
 *@return o path criado e retornado
 */
PATH *path_new(void)
{
    PATH *path;
    path = (PATH *)malloc(sizeof(PATH));
    if(path == NULL)
    {
        printf("Erro ao alocar memoria");
        return NULL;
    }

    return path_set_head(path, NULL) && path_set_tail(path, NULL) ? path : NULL;
}