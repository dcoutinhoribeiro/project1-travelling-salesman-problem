#ifndef PATH_H 
#include <stdbool.h>

    #define PATH_H 

    #define TAM_MAX 10 /*estimativa do tamanho máximo da path*/ 

    #include "node/node.h"

    typedef struct path_ PATH;  

    int path_get_size(PATH *path);  //
    NODE *path_get_head(PATH *path); // 
    NODE *path_get_last(PATH *path); //

    bool path_set_head(PATH *path, NODE *head); //
    bool path_set_last(PATH *path, NODE *last); // 
    bool path_add_after(PATH *path, NODE *node, int key);  //
    bool path_add_beggining(PATH *path, NODE *node); // 
    bool path_add_end(PATH *path, NODE *node); //
    bool path_free(PATH *path); 
    bool path_is_empty(PATH *path); 
    bool path_full(PATH *path); 

    void path_print(PATH *path);
    void *path_copy(PATH *path, PATH *copy);

    NODE *path_delete(PATH *path, int key); //
    NODE *path_delete_first(PATH *path); //
    NODE *path_delete_last(PATH *path); //
    NODE *path_get_last(PATH *path); //
    NODE *path_search(PATH *path, int key); //
    PATH *path_new(int start, int size);  //
    PATH *path_reverse(PATH *path, int position);
    PATH *path_swap(PATH *path, int keyItemA, int keyItemB);
#endif 