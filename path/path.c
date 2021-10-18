#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "path.h"
#include "node/node.h"

struct path_
{
    NODE *head;
    NODE *last
};

bool path_unshift(PATH *path, NODE *node)
{
    if (path == NULL || node == NULL || path_is_full(path))
        return false;

    if (path_is_empty(path))
    {
        path_set_last(path, node);
    }
    else
    {
        node_set_prev(path_get_head(path), node);
    }

    node_set_next(node, path_get_head(path));
    path_set_head(path, node);

    return true;
}

void path_reverse(PATH *path)
{
    if (path == NULL || path_is_empty(path)) return;

    NODE *current, *temp_node;

     for (current = path_get_head(path); current != NULL; current = node_get_prev(current)) {
         temp_node = node_get_prev(current);
         
         node_set_prev(current, node_get_next(current));
         node_set_next(current, temp_node);        
    }

    if(temp_node != NULL) path_set_head(path, node_get_prev(temp_node));

    node_free(temp_node);
}

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
    path_set_last(after_path, path_get_last(path));
    path_set_last(path, NULL);

    return after_path;
}

void path_concat(PATH* path_a, PATH* path_b) {
    if(path_a == NULL || path_b == NULL) return;

    NODE *temp_node;
    temp_node = path_get_last(path_a);
    path_set_last(path_a, path_get_last(path_b));
    node_set_next(temp_node, path_get_head(path_b));
    node_set_prev(path_get_head(path_b), temp_node);

    path_free(path_b);
}

void path_swap(PATH *path, int i, int j)
{
    if (path == NULL)
        return;
    NODE *item_a, *item_b, *item_aux;

    item_a = path_search(path, i);
    item_b = path_search(path, j);

    if (item_a == NULL || item_b == NULL)
        return;

    item_aux = node_create(node_get_key(item_b));

    node_set_prev(item_b, path_get_prev(item_a));
    node_set_next(item_b, node_get_next(item_a));

    node_set_prev(item_a, path_get_prev(item_aux));
    node_set_next(item_a, path_get_prev(item_aux));

    node_free(item_aux);
}

void path_print(PATH *path) {
    if (path == NULL) return;

    NODE *current;

    for(current = path_get_head(path); current != NULL; current = node_get_next(current)) 
        if(node_get_key(current) == path_get_size(path)) 
            printf (" %d ", node_get_key(current));
        else 
            printf (" -> %d ", node_get_key(current));
}

bool path_add_last(PATH *path, NODE *node)
{
    if (path == NULL || node == NULL || path_is_full(path))
        return false;

    if (path_is_empty(path))
    {
        path_set_last(path, node);
    }
    else
    {
        node_set_next(path_get_last(path), node);
        node_set_prev(node, path_get_last(path));
    }

    path_set_last(path, node);

    return true;
}

bool path_is_empty(PATH *path)
{
    return path_get_head(path) == NULL;
}

bool path_full(PATH *path)
{
    if (path == NULL)
        return true;

    return path_get_size(path) == TAM_MAX;
};

void path_copy(PATH *path, PATH *copy)
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

    for (current = path_get_head(path); current != NULL; current = node_get_next(current))
        check = path_push(path_copy, current);

    if (copy != NULL)
        path_free(copy);

    copy = path_copy;
    path_free(path_copy);

    return check;
}

void path_free(PATH **path) {
    if (path == NULL) return; 

    NODE *current; 
    
    current = NULL;
    free (*path);
}

bool path_add_after(PATH *path, NODE *node, int key)
{
    if (path == NULL || node == NULL || path_is_empty(path) || path_full(path))
        return false;

    NODE *current, *found;
    current = path_get_head(path);
    found = path_search(path, key);

    if (found == NULL)
        return false;

    if (node_get_key(path_get_last(path)) == key)
    {
        node_set_next(node, NULL);
        path_set_last(path_get_last(path), node);
    }
    else
    {
        node_set_next(node, node_get_next(found));
        node_set_prev(node_get_next(found), node);
    }

    node_set_prev(node, found);
    node_set_next(found, node);

    return true;
}

NODE *path_delete_first(PATH *path)
{
    if (path == NULL || path_is_empty(path))
        return NULL;

    NODE *temp;
    temp = path_get_head(path);

    if (node_get_next(path_get_head(path)) == NULL)
        path_set_last(path, NULL);
    else
        node_set_next(path_get_head(path), NULL);

    path_set_head(path, node_get_next(path_get_head(path)));

    return temp;
}

NODE *path_delete_last(PATH *path)
{
    if (path == NULL || path_is_empty(path))
        return NULL;

    NODE *temp;
    temp = path_get_last(path);

    if (path_get_head(path) == NULL)
        path_set_head(path, NULL);
    else
        node_set_prev(path_get_last(path), NULL);

    path_set_last(path, node_get_prev(path_get_last(path)));

    return temp;
}

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

NODE *path_delete(PATH *path, int key)
{
    if (path == NULL || path_is_empty(path))
        return NULL;

    NODE *deleted;
    deleted = path_search(path, key);

    if (path_get_key(deleted) == path_get_key(path_get_head(path)))
        path_set_head(path, node_get_next(path_get_head(path)));
    else
        node_set_next(node_get_prev(deleted), node_get_next(deleted));

    if (path_get_key(deleted) == path_get_key(path_get_last(path)))
        path_set_last(path, node_get_prev(deleted));
    else
        node_set_prev(node_get_next(deleted), node_get_prev(deleted));

    return deleted;
}

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

bool path_set_head(PATH *path, NODE *head)
{
    if (path != NULL)
    {
        path->head = head;
        return true;
    }
    return false;
}

bool path_set_last(PATH *path, NODE *last)
{
    if (path != NULL)
    {
        path->last = last;
        return true;
    }
    return false;
}

NODE *path_get_head(PATH *path)
{
    return path != NULL ? path->head : NULL;
}

NODE *path_get_last(PATH *path)
{
    return path != NULL ? path->last : NULL;
}

bool path_is_empty(PATH *path)
{
}

PATH *path_new()
{
    PATH *path;
    path = (PATH *)malloc(sizeof(PATH));

    return path;
}