#ifndef PATH_H 
#include <stdbool.h>

    #define PATH_H 

    #define TAM_MAX_PATH 13 /*estimativa do tamanho máximo da path*/ 
    #define INT_MAX 2147483647

    #include "path_node/path_node.h"

    typedef struct path_ PATH;  

    int path_get_size(PATH *path);  //

    bool path_set_head(PATH *path, PATH_NODE  *head); ////@
    bool path_set_tail(PATH *path, PATH_NODE  *tail); //  //@
    bool path_unshift(PATH *path, PATH_NODE  *path_node); //@
    bool path_push(PATH *path, PATH_NODE  *path_node); //@ 
    bool path_is_empty(PATH *path); // //@
    bool path_is_full(PATH *path); // @@
    bool path_add_after(PATH *path, int index, PATH_NODE  *path_node); // @@

    void path_swap(PATH *path, int i, int j); // @@
    void path_free(PATH **path); // 
    void path_print(PATH *path); // @@

    PATH_NODE  *path_delete(PATH *path, int key); // @@
    PATH_NODE  *path_delete_head(PATH *path); // @
    PATH_NODE  *path_delete_tail(PATH *path); // @@
    PATH_NODE  *path_get_head(PATH *path); //  //@
    PATH_NODE  *path_get_tail(PATH *path); // //@
    PATH_NODE  *path_search(PATH *path, int key); // @@

    PATH *path_new();  //@
    PATH *path_split_after(PATH *path, int key); //
    PATH *path_reverse(PATH *path); //@

#endif 