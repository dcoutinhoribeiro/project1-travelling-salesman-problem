#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "path.h"
#include "node/node.h"

struct path_{ 
    NODE *head;
    NODE *last
};

bool path_add_beggining(PATH *path, NODE *node) {
    if (path == NULL || node == NULL) return false;

    if(path_is_empty(path)) {
        path_set_last(path, node);
    } else {
        node_set_prev(path_get_head(path), node);
    }

   node_set_next(node, path_get_head(path));
   path_set_head(path, node);

   return true;

}

bool path_add_last(PATH *path, NODE *node) {
    if (path == NULL || node == NULL) return false;

    if(path_is_empty(path)) {
        path_set_last(path, node);
    } else {
        node_set_next(path_get_last(path), node);
        node_set_prev(node, path_get_last(path));
    }

   path_set_last(path, node);

   return true;

}

bool path_add_after(PATH *path, NODE *node, int key) {
    if (path == NULL || node == NULL || path_is_empty(path)) return false;

    NODE *current, *found;
    current = path_get_head(path);  
    found = path_search(path, key);

    if(found == NULL) return false;

    if(node_get_key(path_get_last(path)) == key) {
        node_set_next(node, NULL);
        path_set_last(path_get_last(path), node);
    } else {
        node_set_next(node, node_get_next(found));
        node_set_prev(node_get_next(found), node);
    }

    node_set_prev(node, found);
    node_set_next(found, node);
    
    return true;
}


NODE *path_delete_first(PATH *path) {
    if (path == NULL || path_is_empty(path)) return NULL;

    NODE *temp;
    temp = path_get_head(path);

    if(node_get_next(path_get_head(path)) == NULL)
        path_set_last(path, NULL);
    else 
        node_set_next(path_get_head(path), NULL);
    
    path_set_head(path, node_get_next(path_get_head(path)));

    return temp;
}

NODE *path_delete_last(PATH *path) {
    if (path == NULL || path_is_empty(path)) return NULL;

    NODE *temp;
    temp = path_get_last(path);

    if(path_get_head(path) == NULL)
        path_set_head(path, NULL);
    else 
        node_set_prev(path_get_last(path), NULL);

    path_set_last(path, node_get_prev(path_get_last(path)));

    return temp;
}

NODE *path_search(PATH *path, int key) {
    NODE *found = NULL, *current;

    if(path == NULL) return NULL;

    for(current = path_get_head(path); current != NULL; current = path_get_next(current)) 
        if(node_get_key(current) == key) found = current;
    
    return found;
}

NODE *path_delete(PATH *path, int key) {
    if (path == NULL || path_is_empty(path)) return NULL;

    NODE *deleted;
    deleted = path_search(path, key);    

    if(path_get_key(deleted) == path_get_key(path_get_head(path)))
        path_set_head(path, node_get_next(path_get_head(path)));   
    else 
        node_set_next(node_get_prev(deleted), node_get_next(deleted));
  
    if(path_get_key(deleted) == path_get_key(path_get_last(path)))
        path_set_last(path, node_get_prev(deleted));   
    else 
        node_set_prev(node_get_next(deleted), node_get_prev(deleted));

    return deleted;
}

int path_get_size(PATH *path) {
    if(path == NULL) return -1;

    int size = 0;
    
    NODE *current;

    for(current = path_get_head(path); current != NULL; current = path_get_next(current)) {
        size++;
    }

    return size;
}

bool path_set_head(PATH *path, NODE *head) {
    if (path != NULL){
        path->head = head;
        return true;
    }
    return false;
}

bool path_set_last(PATH *path, NODE *last) {
    if (path != NULL){
        path->last = last;
        return true;
    }
    return false;
}

NODE *path_get_head(PATH *path) {
    return path != NULL ? path->head : NULL;
}

NODE *path_get_last(PATH *path) {
    return path != NULL ? path->last : NULL;
}

bool path_is_empty(PATH *path){
}

PATH *path_new(int start, int size) {
    PATH *path;
    path = (PATH *) malloc(sizeof(PATH));
          
    return 
        path != NULL && 
        route_set_size(path, size) &&
        route_set_path(path, path) 
            ? path : NULL;
}