#ifndef PATH_NODE_H
	#define PATH_NODE_H
	#define NOT_FOUND -1
	#include <stdbool.h>

	typedef struct path_node_ PATH_NODE ;

	int path_node_get_key(PATH_NODE  *path_node);//Não é a mesma coisa que a linha 9?
	int path_node_get_city(PATH_NODE  *path_node);//
	bool path_node_free(PATH_NODE  **path_node);
	bool path_node_set_key(PATH_NODE  *path_node, int key);
	bool path_node_set_next(PATH_NODE  *path_node, PATH_NODE  *next);
	bool path_node_set_prev(PATH_NODE  *path_node, PATH_NODE  *prev);
	bool path_node_delete_key(PATH_NODE  **path_node);//adicionei
	void path_node_print(PATH_NODE  *path_node);

	PATH_NODE  *path_node_create(int key);
	PATH_NODE  *path_node_get_prev(PATH_NODE  *path_node);
	PATH_NODE  *path_node_get_next(PATH_NODE  *path_node);
#endif 