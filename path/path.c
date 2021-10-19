#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "path.h"
#include "node/node.h"

struct path_
{
    NODE *head;
    NODE *tail;
};

/*
 *Função para adicionar um NODE a um PATH
 * @param *path  uma variavel ponteiro de PATH com um caminho possível
 * @param *node  uma variavel ponteiro de NODE que contém o número de uma cidade   
 * @retun  um booleano informando se a operação deu certo
 */
bool path_unshift(PATH *path, NODE *node)
{
    if (path == NULL || node == NULL || path_is_full(path))
        return false;

    if (path_is_empty(path))
    {
        //se o caminho esta vazio, o no passa a ser comeco desse caminho
        path_set_tail(path, node);
    }
    else
    {
        //se o caminho nao esta vazio, entao o topo do caminho aponta para 
        //o novo no 
        node_set_prev(path_get_head(path), node);
    }

    //next de no aponta para o topo de path
    node_set_next(node, path_get_head(path));

    //o no e definido como o topo do caminho
    path_set_head(path, node);

    return true;
}

/*
 *Função para reverter um PATH
 * @param *path  uma variavel ponteiro de PATH com um caminho possível
 */
PATH *path_reverse(PATH *path)
{
    if (path == NULL || path_is_empty(path)) return NULL;
 
    NODE *current;
    PATH *reverse_path;

    reverse_path = path_new();

    for(current = path_get_head(path); current != NULL; current = node_get_next(current)) {        
      path_unshift(reverse_path, node_create(node_get_key(current)));
    }

    return reverse_path;

}

/*
 *Função para dividir um PATH a partir de um NODE contendo uma key especifica
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @param  key  uma variavel do tipo inteiro que contém o número de uma cidade   
 * @retun  um variavel do tipo PATH que contem o caminho encontrado apos a divisao
 */
PATH *path_split_after(PATH *path, int key) {
    if(path == NULL) return NULL;

    NODE *found_node; 
    PATH *after_path;

    found_node = path_search(path, key);
    after_path = path_new();
    
    if(found_node == NULL || node_get_next(found_node) == NULL) return NULL;
   
    path_set_head(after_path, node_get_next(found_node));
    node_set_prev(node_get_next(found_node), NULL);
    node_set_next(found_node, NULL);
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

    NODE *temp_node;
    temp_node = path_get_tail(*path_a);
    path_set_tail(*path_a, path_get_head(*path_b));//troquei path_get_tail por path_get_head
    node_set_next(temp_node, path_get_head(*path_b));
    node_set_prev(path_get_head(*path_b), temp_node);

    path_free(path_b);
}

bool path_add_after(PATH *path, int index, NODE *node) {
    if (path == NULL) return false;

    NODE *found, *after_found; 

    found = path_search(path, index);
    after_found = node_get_next(found);

    if(found == NULL) return false;

    if(path_get_size(path) == 1) {
        return path_push(path, node);
    }

   return node_set_next(node, after_found) && node_set_prev(node, found) && node_set_next(found, node) && node_set_prev(after_found, node);
}

/*
 *Função para trocar um NODE de um PATH por outro NODE
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @param   int   uma variavel do tipo inteiro que contem a key de NODE
 * @param   int   uma variavel do tipo inteiro que contem a key de NODE
 */

void path_swap(PATH *path, int i, int j)
{
    if (path == NULL) return;

    NODE *item_a, *item_b, *prev_a, *prev_b, *next_a, *next_b, *prev_aux_a, *next_aux_a;

    item_a = path_search(path, i);
    item_b = path_search(path, j);

    if (item_a == NULL || item_b == NULL)
        return;

   path_add_after(path, i, node_create(INT_MAX - j));
   path_delete(path,i);
   path_add_after(path, j, node_create(i));
   path_delete(path,j);
   node_set_key(path_search(path, INT_MAX - j), j);
}

/*
 *Função para imprimir um PATH
 * @param  *path  uma variavel ponteiro de PATH com um caminho possível
 * @param *node  uma variavel ponteiro de NODE que contém o número de uma cidade   
 * 
 */
void path_print(PATH *path) {
    if (path == NULL) return;

    NODE *current;

    printf ("\n ");

    for(current = path_get_head(path); current != NULL; current = node_get_next(current)) {
        if(current == path_get_head(path)) 
            printf(" %d ", node_get_key(current));
        else 
            printf (" -> %d ", node_get_key(current)); 
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
bool path_push(PATH *path, NODE *node)
{
    if (path == NULL || node == NULL || path_is_full(path))
        return false;

    if (path_is_empty(path))
    {
        path_set_tail(path, node);
        //adicionei path_set_head
        path_set_head(path,node);
    }
    else
    {
        node_set_next(path_get_tail(path), node);
        node_set_prev(node, path_get_tail(path));
    }

    path_set_tail(path, node);

    return true;
}

/*se for pra copiar um path
PATH path_copy(PATH *path)
{
    if (path == NULL)
    {
        copy = NULL;
        return true;
    }

    NODE *current;
    PATH *path_copy;
    bool check = true;
    path_copy = path_new();

    //colocando cada elemento do path antigo no path novo
    for (current = path_get_head(path); current != NULL; current = node_get_next(current))
        check = path_push(path_copy, current);

    if (copy != NULL)
        path_free(copy);

    
    return path_copy;
}*/

//path_empty nao precisa estar declarado no .h
/*
 *Função para esvaziar um PATH
 * @param  *head  uma variavel ponteiro de NODE com o primeiro NODE de PATH
 */
bool path_empty(PATH *path){
    return true;
    /*if(path == NULL) return false;
    NODE *current;
    bool check = true;
    for (current = node_get_next(path_get_head(path)); current != NULL; current = node_get_next(current)){
        check = node_free(*node_get_prev(current));     
        node_set_prev(current, NULL);
    }
    check = node_free(current);
    current = NULL;
    path_set_head(path,NULL);
    path_set_tail(path,NULL);
    return check;*/
}

/*
 *Função para apagar um PATH
 * @param  **path  uma variavel ponteiro duplo de PATH com o PATH original
 */
bool path_free(PATH **path) {
    bool check = true;

    if(*path == NULL) return false;
    check = path_empty(*path);
    free(*path);
    *path = NULL; 

    return check;
}


/*bool path_add_after(PATH *path, NODE *node, int key)
{
    if (path == NULL || node == NULL || path_is_empty(path) || path_full(path))
        return false;

    NODE *current, *found;
    current = path_get_head(path);
    found = path_search(path, key);

    if (found == NULL)
        return false;

    if (node_get_key(path_get_tail(path)) == key)
    {
        node_set_next(node, NULL);
        //path_set_tail(path_get_tail(path), node);
        path_set_tail(path, node);
    }
    else
    {
        //nao esta colocando antes de found?
        node_set_next(node, node_get_next(found));
        node_set_prev(node_get_next(found), node);
    }

    node_set_prev(node, found);
    node_set_next(found, node);

    return true;
}*/

/*
 *Função para apagar o primeiro NODE de um PATH
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @return retorna o NODE que estava no comeco do PATH 
 */
NODE *path_delete_head(PATH *path)
{
    if (path == NULL || path_is_empty(path))
        return NULL;

    NODE *temp;
    temp = path_get_head(path);

    if(path_get_size(path) == 1) {
        path_set_head(path, NULL);
        path_set_tail(path, NULL);

        return temp;
    }
    
    node_set_prev(node_get_next(temp), NULL);
    path_set_head(path, node_get_next(temp));

    return temp;
}

/*
 *Função para apagar o ultimo NODE de um PATH
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @return retorna o NODE que estava no fim do PATH 
 */
NODE *path_delete_tail(PATH *path)
{
   if (path == NULL || path_is_empty(path))
        return NULL;

    NODE *temp;
    temp = path_get_tail(path);

    if(path_get_size(path) == 1) {
        path_set_head(path, NULL);
        path_set_tail(path, NULL);

        return temp;
    }

    node_set_next(node_get_prev(temp), NULL);
    path_set_tail(path, node_get_prev(temp));

    return temp;
}

/*
 *Função para procurar por uma key no PATH
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @param   key   uma variavel inteira com o valor da key (cidade)
 * @return retorna o NODE com a key procurada 
 */
NODE *path_search(PATH *path, int key)
{
    NODE *found = NULL, *current;

    if (path == NULL)
        return NULL;

    for (current = path_get_head(path); current != NULL; current = node_get_next(current))
        if (node_get_key(current) == key)
            found = current;

    return found;
}

/*
 *Função para deletar um NODE com uma key especifica
 * @param  *path  uma variavel ponteiro de PATH com um path qualquer
 * @param   key   uma variavel inteira com o valor da key (cidade)
 * @return retorna o NODE deletado 
 */
NODE *path_delete(PATH *path, int key)
{
    if (path == NULL || path_is_empty(path))
        return NULL;

    NODE *deleted;
    deleted = path_search(path, key);

    if (node_get_key(deleted) == node_get_key(path_get_head(path)))
        path_set_head(path, node_get_next(path_get_head(path)));
    else
        node_set_next(node_get_prev(deleted), node_get_next(deleted));

    if (node_get_key(deleted) == node_get_key(path_get_tail(path)))
        path_set_tail(path, node_get_prev(deleted));
    else
        node_set_prev(node_get_next(deleted), node_get_prev(deleted));

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

    NODE *current;

    for (current = path_get_head(path); current != NULL; current = node_get_next(current))
    {
        size++;
    }

    return size;
}

/*
 *Função para alocar uma head a um path
 * @param  *path uma variavel ponteiro de PATH com um path qualquer
 * @param  *head uma variavel ponteir de NODE com o node que sera o começo do path
 * @return um bool informando se a operacao deu certo
 */
bool path_set_head(PATH *path, NODE *head)
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
 * @param  *tail uma variavel ponteir de NODE com o node que sera o fim do path
 * @return um bool informando se a operacao deu certo
 */
bool path_set_tail(PATH *path, NODE *tail)
{
    if (path != NULL)
    {
        path->tail = tail;
        return true;
    }
    return false;
}

/*
 *Função que retorna o node do comeco de um path
 * @param  *path uma variavel ponteiro de PATH com um path qualquer
 * @return um node que e comeco do path
 */
NODE *path_get_head(PATH *path)
{
    return path != NULL ? path->head : NULL;
}

/*
 *Função que retorna o node do fim de um path
 * @param  *path uma variavel ponteiro de PATH com um path qualquer
 * @return um node que e fim do path
 */
NODE *path_get_tail(PATH *path)
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