#include <stdio.h>
#include "path/path.h"
#include "path/node/node.h"

void main (int argc, char **argv){
    PATH *path, *path2;

    path = path_new();

    printf("\n Hello World \n");

    path_push(path, node_create(1));
    path_push(path, node_create(2));
    path_push(path, node_create(3));
    path_push(path, node_create(4));
    path_push(path, node_create(5));
    
    path2 = path_new();
    path_push(path2, node_create(6));

    path_concat(&path, &path2);

    path_add_after(path, 4, node_create(10));

    path_print(path);

    path_swap(path, 1, 6);
    path_print(path);
    
    path_free(&path);
 
    path_print(path);

}