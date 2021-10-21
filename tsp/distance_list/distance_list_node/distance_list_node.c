#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "distance_list_node.h"
 
struct distance_list_node_{ 
    int key;
    int from;
    int to;
    int distance;
    DISTANCE_LIST_NODE  *next;
    DISTANCE_LIST_NODE  *prev;
};

DISTANCE_LIST_NODE  *distance_list_node_get_prev(DISTANCE_LIST_NODE  *distance_list_node){
  if(distance_list_node == NULL) return NULL;

  return distance_list_node->prev;
}

DISTANCE_LIST_NODE  *distance_list_node_get_next(DISTANCE_LIST_NODE  *distance_list_node){
  if(distance_list_node == NULL) return NULL;

  return distance_list_node->next;
}

bool distance_list_node_set_prev(DISTANCE_LIST_NODE  *distance_list_node, DISTANCE_LIST_NODE  *prev){
  if (distance_list_node == NULL) return false;

  distance_list_node->prev = prev;

  return true;
}

bool distance_list_node_set_next(DISTANCE_LIST_NODE  *distance_list_node, DISTANCE_LIST_NODE  *next){
  if (distance_list_node == NULL) return false;

  distance_list_node->next = next;

  return true;
}

DISTANCE_LIST_NODE  *distance_list_node_create (int key){
          DISTANCE_LIST_NODE  *distance_list_node;
          
          distance_list_node = (DISTANCE_LIST_NODE  *) malloc(sizeof(DISTANCE_LIST_NODE ));
          
          if (distance_list_node != NULL){
             distance_list_node->key = key;
             return(distance_list_node);
          }
          return(NULL);
}

bool distance_list_node_free(DISTANCE_LIST_NODE  **distance_list_node){
   if (*distance_list_node != NULL){
      free (*distance_list_node);
      *distance_list_node = NULL; 
      return(true);
   }
   return(false);
}

int distance_list_node_get_key(DISTANCE_LIST_NODE  *distance_list_node){
    if (distance_list_node != NULL)
      return(distance_list_node->key);
    exit(1);
}

bool distance_list_node_set_key(DISTANCE_LIST_NODE  *distance_list_node, int key){
  if (distance_list_node != NULL){
    distance_list_node->key = key;
    return (true);
  }
  return (false);
}

int distance_list_node_get_to(DISTANCE_LIST_NODE  *distance_list_node){
    if (distance_list_node != NULL)
      return(distance_list_node->to);
    exit(1);
}

bool distance_list_node_set_to(DISTANCE_LIST_NODE  *distance_list_node, int to){
  if (distance_list_node != NULL){
    distance_list_node->to = to;
    return (true);
  }
  return (false);
}

int distance_list_node_get_from(DISTANCE_LIST_NODE  *distance_list_node){
    if (distance_list_node != NULL)
      return(distance_list_node->from);
    exit(1);
}

bool distance_list_node_set_from(DISTANCE_LIST_NODE  *distance_list_node, int from){
  if (distance_list_node != NULL){
    distance_list_node->from = from;
    return (true);
  }
  return (false);
}

int distance_list_node_get_distance(DISTANCE_LIST_NODE  *distance_list_node){
    if (distance_list_node != NULL)
      return(distance_list_node->distance);
    exit(1);
}

bool distance_list_node_set_distance(DISTANCE_LIST_NODE  *distance_list_node, int distance){
  if (distance_list_node != NULL){
    distance_list_node->distance = distance;
    return (true);
  }
  return (false);
}

void distance_list_node_print(DISTANCE_LIST_NODE  *distance_list_node){
  if (distance_list_node != NULL)
    printf("\n-->distance_list_node: %d\n", distance_list_node->key);
}

