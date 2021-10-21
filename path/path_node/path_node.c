#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "path_node.h"
 
struct path_node_{ 
    int key;
    PATH_NODE  *next;
    PATH_NODE  *prev;
};

PATH_NODE  *path_node_get_prev(PATH_NODE  *path_node){
  if(path_node == NULL) return NULL;

  return path_node->prev;
}

PATH_NODE  *path_node_get_next(PATH_NODE  *path_node){
  if(path_node == NULL) return NULL;

  return path_node->next;
}

bool path_node_set_prev(PATH_NODE  *path_node, PATH_NODE  *prev){
  if (path_node == NULL) return false;

  path_node->prev = prev;

  return true;
}

bool path_node_set_next(PATH_NODE  *path_node, PATH_NODE  *next){
  if (path_node == NULL) return false;

  path_node->next = next;

  return true;
}

PATH_NODE  *path_node_create (int key){
          PATH_NODE  *path_node;
          
          path_node = (PATH_NODE  *) malloc(sizeof(PATH_NODE ));
          
          if (path_node != NULL){
             path_node->key = key;
             return(path_node);
          }
          return(NULL);
}

bool path_node_free(PATH_NODE  **path_node){
   if (*path_node != NULL){
      free (*path_node);
      *path_node = NULL; 
      return(true);
   }
   return(false);
}

int path_node_get_key(PATH_NODE  *path_node){
    if (path_node != NULL)
      return(path_node->key);
    exit(1);
}

bool path_node_set_key(PATH_NODE  *path_node, int key){
  if (path_node != NULL){
    path_node->key = key;
    return (true);
  }
  return (false);
}

void path_node_print(PATH_NODE  *path_node){
     if (path_node != NULL)
        printf("\n-->path_node: %d\n", path_node->key);
}

