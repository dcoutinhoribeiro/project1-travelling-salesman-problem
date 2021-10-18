#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "node.h"
 
struct node_{ 
    int key;
    NODE *next;
    NODE *prev;
};

NODE *node_get_prev(NODE *node){
  if(node == NULL) return NULL;

  return node->prev;
}

NODE *node_get_next(NODE *node){
  if(node == NULL) return NULL;

  return node->next;
}

bool node_set_prev(NODE *node, NODE *prev){
  if (node == NULL) return false;

  node->prev = prev;

  return true;
}

bool node_set_next(NODE *node, NODE *next){
  if (node == NULL) return false;

  node->next = next;

  return true;
}

NODE *node_create (int key){
          NODE *node;
          
          node = (NODE *) malloc(sizeof(NODE));
          
          if (node != NULL){
             node->key = key;
             return(node);
          }
          return(NULL);
}

bool node_free(NODE **node){
   if (*node != NULL){
      free (*node);
      *node = NULL; 
      return(true);
   }
   return(false);
}

int node_get_key(NODE *node){
    if (node != NULL)
      return(node->key);
    exit(1);
}

bool node_set_key(NODE *node, int key){
  if (node != NULL){
    node->key = key;
    return (true);
  }
  return (false);
}

void node_print(NODE *node){
     if (node != NULL)
        printf("\n-->node: %d\n", node->key);
}

