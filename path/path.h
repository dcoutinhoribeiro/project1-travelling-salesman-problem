#ifndef PATH_H 
#include <stdbool.h>

    #define PATH_H 

    #define TAM_MAX_PATH 13 /*estimativa do tamanho máximo da path*/ 
    #define INT_MAX 2147483647

    #include "path_node/path_node.h"
    #include "../tsp/distance_list/distance_list.h"


    typedef struct path_ PATH;  

    int path_get_size(PATH *path);  //
    int path_calculate_distance(PATH *path, DISTANCE_LIST *distance_list, int start);

    bool path_set_head(PATH *path, PATH_NODE  *head); ////@
    bool path_set_tail(PATH *path, PATH_NODE  *tail); //  //@
    bool path_unshift(PATH *path, PATH_NODE  *path_node); //@
    bool path_push(PATH *path, PATH_NODE  *path_node); //@ 
    bool path_insert_before(PATH *path, PATH_NODE *path_node, PATH_NODE *new_path_node); //
    bool path_insert_after(PATH *path, PATH_NODE *path_node, PATH_NODE *new_path_node);
    bool path_is_empty(PATH *path); // //@
    bool path_is_full(PATH *path); // @@

    void path_swap(PATH *path, int i, int j); // @@
    void path_free(PATH **path); // 
    void path_print_with_start(PATH *path, int start); // @@
    void path_print(PATH *path); // @@
    void path_populate(PATH *path, int size, int start, bool is_random);  //@
    void path_copy_to(PATH* path, PATH *source_path);
    void  path_delete(PATH *path, PATH_NODE *path_node); // @@
    void  path_delete_head(PATH *path); // @
    void  path_delete_tail(PATH *path); // @@

    PATH_NODE  *path_get_head(PATH *path); //  //@
    PATH_NODE  *path_get_tail(PATH *path); // //@
    PATH_NODE  *path_search(PATH *path, int key); // @@
    
    PATH *path_get_next_permutation(PATH *route);
    PATH *path_new();  //@

#endif 