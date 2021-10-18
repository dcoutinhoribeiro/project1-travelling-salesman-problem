#ifndef PATH_H 
#include <stdbool.h>

    #define PATH_H 

    #define TAM_MAX 10 /*estimativa do tamanho máximo da path*/ 

    #include "node/node.h"

    typedef struct path_ PATH;  

    int path_get_size(PATH *path);  //

    NODE *path_get_head(PATH *path); // 
    NODE *path_get_tail(PATH *path); //

    bool path_set_head(PATH *path, NODE *head); //
    bool path_set_tail(PATH *path, NODE *tail); // 
    bool path_add_after(PATH *path, NODE *node, int key);  //
    bool path_unshift(PATH *path, NODE *node); // 
    bool path_push(PATH *path, NODE *node); 
    bool path_is_empty(PATH *path); //
    bool path_is_full(PATH *path); //
    bool path_free(PATH **path); //
    bool path_empty(PATH *path);

    void path_copy(PATH *path, PATH *copy); //
    void path_swap(PATH *path, int i, int j); //
    void path_print(PATH *path); //
    void path_reverse(PATH *path); //
    void path_concat(PATH **path_a, PATH **path_b); //

    NODE *path_delete(PATH *path, int key); //
    NODE *path_delete_first(PATH *path); //
    NODE *path_delete_tail(PATH *path); //
    NODE *path_get_tail(PATH *path); //
    NODE *path_search(PATH *path, int key); //

    PATH *path_new();  // 
    PATH *path_split_after(PATH *path, int key); //

#endif 