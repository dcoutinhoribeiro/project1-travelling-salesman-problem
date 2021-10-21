#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "path.h"
#include "path_node/path_node.h"

struct path_
{
    PATH_NODE  *head;
    PATH_NODE  *tail;
};

/*
 *Função para adicionar um PATH_NODE  a um PATH
 * @param *path  uma variavel ponteiro de PATH com um caminho possível
 * @param *path_node  uma variavel ponteiro de PATH_NODE  que contém o número de uma cidade   
 * @retun  um booleano informando se a operação deu certo
 */
bool path_unshift(PATH *path, PATH_NODE  *path_node)
{
    if (path == NULL || path_node == NULL || path_is_full(path))
        return false;

    if (path_is_empty(path))
    {
        //se o caminho esta vazio, o no passa a ser comeco desse caminho
        path_set_tail(path, path_node);
    }
    else
    {
        //se o caminho nao esta vazio, entao o topo do caminho aponta para 
        //o novo no 
        path_node_set_prev(path_get_head(path), path_node);
    }

    //next de no aponta para o topo de path
    path_node_set_next(path_node, path_get_head(path));

    //o no e definido como o topo do caminho
    path_set_head(path, path_node);

    return true;
}

/*
 *Função para reverter um PATH
 * @param *path  uma variavel ponteiro de PATH com um caminho possível
 */
PATH *path_reverse(PATH *path)
{
    if (path == NULL || path_is_empty(path)) return NULL;
 
    PATH_NODE  *current;
    PATH *reverse_path;

    reverse_path = path_new();

    for(current = path_get_head(path); current != NULL; current = path_node_get_next(current)) {        
      path_unshift(reverse_path, path_node_create(path_node_get_key(current)));
    }

    return reverse_path;

}

/*
 *Função para dividir um PATH a partir de um PATH_NODE  contendo uma key especifica
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @param  key  uma variavel do tipo inteiro que contém o número de uma cidade   
 * @retun  um variavel do tipo PATH que contem o caminho encontrado apos a divisao
 */
PATH *path_split_after(PATH *path, int key) {
    if(path == NULL) return NULL;

    PATH_NODE  *found_path_node; 
    PATH *after_path;

    found_path_node = path_search(path, key);
    after_path = path_new();
    
    if(found_path_node == NULL || path_node_get_next(found_path_node) == NULL) return NULL;
   
    path_set_head(after_path, path_node_get_next(found_path_node));
    path_node_set_prev(path_node_get_next(found_path_node), NULL);
    path_node_set_next(found_path_node, NULL);
    path_set_tail(after_path, path_get_tail(path));
    path_set_tail(path, NULL);

    return after_path;
}

/*
 *Função para concatenar duas variaveis do tipo PATH
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível 
 */
void path_concat(PATH** path_a, PATH** path_b) {
    if(*path_a == NULL || *path_b == NULL) return;

    PATH_NODE  *temp_path_node;
    temp_path_node = path_get_tail(*path_a);
    path_set_tail(*path_a, path_get_head(*path_b));//troquei path_get_tail por path_get_head
    path_node_set_next(temp_path_node, path_get_head(*path_b));
    path_node_set_prev(path_get_head(*path_b), temp_path_node);

    path_free(path_b);
}

bool path_add_after(PATH *path, int index, PATH_NODE  *path_node) {
    if (path == NULL) return false;

    PATH_NODE  *found, *after_found; 

    found = path_search(path, index);
    after_found = path_node_get_next(found);

    if(found == NULL) return false;

    if(path_get_size(path) == 1) {
        return path_push(path, path_node);
    }

   return path_node_set_next(path_node, after_found) && path_node_set_prev(path_node, found) && path_node_set_next(found, path_node) && path_node_set_prev(after_found, path_node);
}

/*
 *Função para trocar um PATH_NODE  de um PATH por outro PATH_NODE 
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @param   int   uma variavel do tipo inteiro que contem a key de PATH_NODE 
 * @param   int   uma variavel do tipo inteiro que contem a key de PATH_NODE 
 */

void path_swap(PATH *path, int i, int j)
{
    if (path == NULL) return;

    PATH_NODE  *item_a, *item_b, *prev_a, *prev_b, *next_a, *next_b, *prev_aux_a, *next_aux_a;

    item_a = path_search(path, i);
    item_b = path_search(path, j);

    if (item_a == NULL || item_b == NULL)
        return;

   path_add_after(path, i, path_node_create(INT_MAX - j));
   path_delete(path,i);
   path_add_after(path, j, path_node_create(i));
   path_delete(path,j);
   path_node_set_key(path_search(path, INT_MAX - j), j);
}

/*
 *Função para imprimir um PATH
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @param *path_node  uma variavel ponteiro de PATH_NODE  que contém o número de uma cidade   
 * 
 */
void path_print(PATH *path) {
    if (path == NULL) return;

    PATH_NODE  *current;

    printf ("\n ");

    for(current = path_get_head(path); current != NULL; current = path_node_get_next(current)) {
        if(current == path_get_head(path)) 
            printf(" %d ", path_node_get_key(current));
        else 
            printf (" -> %d ", path_node_get_key(current)); 
    }

    printf ("\n ");

}
/*
 *Função para adicionar no final
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @retun  um booleano informando se a operação deu certo
 */
/*
 *Função para checar se uma caminho está vazio
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @retun  um booleano informando se a operação deu certo
 */
/*bool path_is_empty(PATH *path)
{
    return path_get_head(path) == NULL;
}*/

/*
 *Função para checar se uma caminho está cheio
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @retun  um booleano informando se a operação deu certo
 */
bool path_is_full(PATH *path)
{
    if (path == NULL)
        return true;

    return path_get_size(path) == TAM_MAX;
};
bool path_push(PATH *path, PATH_NODE  *path_node)
{
    if (path == NULL || path_node == NULL || path_is_full(path))
        return false;

    if (path_is_empty(path))
    {
        path_set_tail(path, path_node);
        //adicionei path_set_head
        path_set_head(path,path_node);
    }
    else
    {
        path_node_set_next(path_get_tail(path), path_node);
        path_node_set_prev(path_node, path_get_tail(path));
    }

    path_set_tail(path, path_node);

    return true;
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


/*
 *Função para apagar o primeiro PATH_NODE  de um PATH
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @return retorna o PATH_NODE  que estava no comeco do PATH 
 */
PATH_NODE  *path_delete_head(PATH *path)
{
    if (path == NULL || path_is_empty(path))
        return NULL;

    PATH_NODE  *temp;
    temp = path_get_head(path);

    if(path_get_size(path) == 1) {
        path_set_head(path, NULL);
        path_set_tail(path, NULL);

        return temp;
    }
    
    path_node_set_prev(path_node_get_next(temp), NULL);
    path_set_head(path, path_node_get_next(temp));

    return temp;
}

/*
 *Função para apagar o ultimo PATH_NODE  de um PATH
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @return retorna o PATH_NODE  que estava no fim do PATH 
 */
PATH_NODE  *path_delete_tail(PATH *path)
{
   if (path == NULL || path_is_empty(path))
        return NULL;

    PATH_NODE  *temp;
    temp = path_get_tail(path);

    if(path_get_size(path) == 1) {
        path_set_head(path, NULL);
        path_set_tail(path, NULL);

        return temp;
    }

    path_node_set_next(path_node_get_prev(temp), NULL);
    path_set_tail(path, path_node_get_prev(temp));

    return temp;
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

/*
 *Função para deletar um PATH_NODE  com uma key especifica
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @param   key   uma variavel inteira com o valor da key (cidade)
 * @return retorna o PATH_NODE  deletado 
 */
PATH_NODE  *path_delete(PATH *path, int key)
{
    if (path == NULL || path_is_empty(path))
        return NULL;

    PATH_NODE  *deleted;
    deleted = path_search(path, key);

    if (path_node_get_key(deleted) == path_node_get_key(path_get_head(path)))
        path_set_head(path, path_node_get_next(path_get_head(path)));
    else
        path_node_set_next(path_node_get_prev(deleted), path_node_get_next(deleted));

    if (path_node_get_key(deleted) == path_node_get_key(path_get_tail(path)))
        path_set_tail(path, path_node_get_prev(deleted));
    else
        path_node_set_prev(path_node_get_next(deleted), path_node_get_prev(deleted));

    return deleted;
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
    return path_get_head(path) == NULL && path_get_tail(path) == NULL;
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