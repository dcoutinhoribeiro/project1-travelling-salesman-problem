#ifndef DISTANCE_LIST_H 
#include <stdbool.h>

    #define DISTANCE_LIST_H 

    #define TAM_MAX 10000 /*estimativa do tamanho máximo da distance_list*/ 
    #define INT_MAX 2147483647

    #include "distance_list_node/distance_list_node.h"

    typedef struct distance_list_ DISTANCE_LIST;  

    int distance_list_get_size(DISTANCE_LIST *distance_list);  //
    int distance_list_node_get_distance_from_to(DISTANCE_LIST *distance_list, int from, int to);

    bool distance_list_is_full(DISTANCE_LIST *distance_list);
    bool distance_list_set_head(DISTANCE_LIST *distance_list, DISTANCE_LIST_NODE  *head); ////@
    bool distance_list_set_tail(DISTANCE_LIST *distance_list, DISTANCE_LIST_NODE  *tail); //  //@
    bool distance_list_push(DISTANCE_LIST *distance_list, DISTANCE_LIST_NODE  *distance_list_node); //@ 
    bool distance_list_is_empty(DISTANCE_LIST *distance_list); // //@
    bool distance_list_is_full(DISTANCE_LIST *distance_list); // @@

    void distance_list_free(DISTANCE_LIST **distance_list); // 
    void distance_list_print(DISTANCE_LIST *distance_list); // @@

    DISTANCE_LIST_NODE  *distance_list_delete(DISTANCE_LIST *distance_list, int key); // @@
    DISTANCE_LIST_NODE  *distance_list_delete_head(DISTANCE_LIST *distance_list); // @
    DISTANCE_LIST_NODE  *distance_list_delete_tail(DISTANCE_LIST *distance_list); // @@
    DISTANCE_LIST_NODE  *distance_list_get_head(DISTANCE_LIST *distance_list); //  //@
    DISTANCE_LIST_NODE  *distance_list_get_tail(DISTANCE_LIST *distance_list); // //@
    DISTANCE_LIST_NODE  *distance_list_search_with_from_to(DISTANCE_LIST *distance_list, int from, int to); // @@
    DISTANCE_LIST_NODE  *distance_list_search(DISTANCE_LIST *distance_list, int key); // @@

    DISTANCE_LIST *distance_list_new();  //@

#endif 