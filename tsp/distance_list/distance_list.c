#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "distance_list.h"
#include "distance_list_node/distance_list_node.h"

struct distance_list_
{
    DISTANCE_LIST_NODE  *head;
    DISTANCE_LIST_NODE  *tail;
};

int distance_list_node_get_distance_from_to(DISTANCE_LIST *distance_list, int from, int to) {
    if (distance_list == NULL) return -1;
 
    DISTANCE_LIST_NODE *node;

    node = distance_list_search_with_from_to(distance_list, from, to);

    if(node == NULL) node = distance_list_search_with_from_to(distance_list, to, from);

    return node == NULL ? -1 : distance_list_node_get_distance(node);
}

void distance_list_print(DISTANCE_LIST *distance_list) {
    if (distance_list == NULL) return;

    DISTANCE_LIST_NODE  *current;

    printf ("\n ORIGEM DESTINO DISTANCIA \n");
    
    for(current = distance_list_get_head(distance_list); current != NULL; current = distance_list_node_get_next(current)) 
        printf("\n %d \t %d \t %d \n", distance_list_node_get_from(current),  distance_list_node_get_to(current),  distance_list_node_get_distance(current));
}

bool distance_list_is_full(DISTANCE_LIST *distance_list) 
{
    if (distance_list == NULL)
        return true;

    return distance_list_get_size(distance_list) == TAM_MAX;
};

bool distance_list_push(DISTANCE_LIST *distance_list, DISTANCE_LIST_NODE  *distance_list_node)
{
    if (distance_list == NULL || distance_list_node == NULL || distance_list_is_full(distance_list))
        return false;

    if (distance_list_is_empty(distance_list))
    {
        distance_list_set_tail(distance_list, distance_list_node);
        //adicionei distance_list_set_head
        distance_list_set_head(distance_list,distance_list_node);
    }
    else
    {
        distance_list_node_set_next(distance_list_get_tail(distance_list), distance_list_node);
        distance_list_node_set_prev(distance_list_node, distance_list_get_tail(distance_list));
    }

    distance_list_set_tail(distance_list, distance_list_node);

    return true;
}


void distance_list_free(DISTANCE_LIST **distance_list) {
    if(*distance_list == NULL) return ;
        free(*distance_list);
    *distance_list = NULL; 
}

DISTANCE_LIST_NODE  *distance_list_delete_head(DISTANCE_LIST *distance_list)
{
    if (distance_list == NULL || distance_list_is_empty(distance_list))
        return NULL;

    DISTANCE_LIST_NODE  *temp;
    temp = distance_list_get_head(distance_list);

    if(distance_list_get_size(distance_list) == 1) {
        distance_list_set_head(distance_list, NULL);
        distance_list_set_tail(distance_list, NULL);

        return temp;
    }
    
    distance_list_node_set_prev(distance_list_node_get_next(temp), NULL);
    distance_list_set_head(distance_list, distance_list_node_get_next(temp));

    return temp;
}

DISTANCE_LIST_NODE  *distance_list_delete_tail(DISTANCE_LIST *distance_list)
{
   if (distance_list == NULL || distance_list_is_empty(distance_list))
        return NULL;

    DISTANCE_LIST_NODE  *temp;
    temp = distance_list_get_tail(distance_list);

    if(distance_list_get_size(distance_list) == 1) {
        distance_list_set_head(distance_list, NULL);
        distance_list_set_tail(distance_list, NULL);

        return temp;
    }

    distance_list_node_set_next(distance_list_node_get_prev(temp), NULL);
    distance_list_set_tail(distance_list, distance_list_node_get_prev(temp));

    return temp;
}

DISTANCE_LIST_NODE  *distance_list_search_with_from_to(DISTANCE_LIST *distance_list, int from, int to)
{
    DISTANCE_LIST_NODE  *found = NULL, *current;

    if (distance_list == NULL)
        return NULL;

    for (current = distance_list_get_head(distance_list); current != NULL; current = distance_list_node_get_next(current))
        if (distance_list_node_get_from(current) == from && distance_list_node_get_to(current) == to)
            found = current;

    return found;
}

DISTANCE_LIST_NODE  *distance_list_search(DISTANCE_LIST *distance_list, int key)
{
    DISTANCE_LIST_NODE  *found = NULL, *current;

    if (distance_list == NULL)
        return NULL;

    for (current = distance_list_get_head(distance_list); current != NULL; current = distance_list_node_get_next(current))
        if (distance_list_node_get_from(current) == key)
            found = current;

    return found;
}



DISTANCE_LIST_NODE  *distance_list_delete(DISTANCE_LIST *distance_list, int key)
{
    if (distance_list == NULL || distance_list_is_empty(distance_list))
        return NULL;

    DISTANCE_LIST_NODE  *deleted;
    deleted = distance_list_search(distance_list, key);

    if (distance_list_node_get_key(deleted) == distance_list_node_get_key(distance_list_get_head(distance_list)))
        distance_list_set_head(distance_list, distance_list_node_get_next(distance_list_get_head(distance_list)));
    else
        distance_list_node_set_next(distance_list_node_get_prev(deleted), distance_list_node_get_next(deleted));

    if (distance_list_node_get_key(deleted) == distance_list_node_get_key(distance_list_get_tail(distance_list)))
        distance_list_set_tail(distance_list, distance_list_node_get_prev(deleted));
    else
        distance_list_node_set_prev(distance_list_node_get_next(deleted), distance_list_node_get_prev(deleted));

    return deleted;
}


int distance_list_get_size(DISTANCE_LIST *distance_list)
{
    if (distance_list == NULL)
        return -1;

    int size = 0;

    DISTANCE_LIST_NODE  *current;

    for (current = distance_list_get_head(distance_list); current != NULL; current = distance_list_node_get_next(current))
    {
        size++;
    }

    return size;
}

bool distance_list_set_head(DISTANCE_LIST *distance_list, DISTANCE_LIST_NODE  *head)
{
    if (distance_list != NULL)
    {
        distance_list->head = head;
        return true;
    }
    return false;
}

bool distance_list_set_tail(DISTANCE_LIST *distance_list, DISTANCE_LIST_NODE  *tail)
{
    if (distance_list != NULL)
    {
        distance_list->tail = tail;
        return true;
    }
    return false;
}

DISTANCE_LIST_NODE  *distance_list_get_head(DISTANCE_LIST *distance_list)
{
    return distance_list != NULL ? distance_list->head : NULL;
}

DISTANCE_LIST_NODE  *distance_list_get_tail(DISTANCE_LIST *distance_list)
{
    return distance_list != NULL ? distance_list->tail : NULL;
}

bool distance_list_is_empty(DISTANCE_LIST *distance_list)
{
    return distance_list_get_head(distance_list) == NULL && distance_list_get_tail(distance_list) == NULL;
}

DISTANCE_LIST *distance_list_new(void)
{
    DISTANCE_LIST *distance_list;
    distance_list = (DISTANCE_LIST *)malloc(sizeof(DISTANCE_LIST));
    if(distance_list == NULL)
    {
        printf("Erro ao alocar memoria");
        return NULL;
    }

    return distance_list_set_head(distance_list, NULL) && distance_list_set_tail(distance_list, NULL) ? distance_list : NULL;
}