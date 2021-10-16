#ifndef PATH_H 
    #define PATH_H 

    #define TAM_MAX 5 /*estimativa do tamanho máximo da path*/ 
    #define TRUE 1 /*define tipo booleano – não existe na linguagem C*/ 
    #define FALSE 0 
    #define boolean int //define um tipo booleano 
    #define inicial 0 
    #define ERRO -32000 

    #include "item/item.h"

    typedef struct path_ PATH;  

    PATH *path_create(void); 
    boolean path_insert(PATH *path, ITEM *item); 
    boolean path_free(PATH **path); 
    boolean path_remove_node(PATH *path); 
    ITEM *path_search(int x, PATH *l);
    int path_size(PATH *path); 
    boolean path_empty(PATH *path); 
    boolean path_full(PATH *path); 
    void path_print(PATH *path);
    void path_reverse_position(PATH *path, int position);
    void path_swap(PATH *path, int keyItemA, int keyItemB);

#endif 