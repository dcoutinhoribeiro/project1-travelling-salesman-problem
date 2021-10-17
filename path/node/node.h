#ifndef NODE_H
	#define NODE_H
	#include <stdbool.h>

	typedef struct node_ NODE;

	int node_get_key(NODE *node);
	int node_get_city(NODE *node);
	bool node_free(NODE **node);
	bool node_set_key(NODE *node, int key);
	bool node_set_next(NODE *node, NODE *next);
	bool node_set_prev(NODE *node, NODE *prev);
	void node_print(NODE *node);

	NODE *node_create(int key);
	NODE *node_get_prev(NODE *node);
	NODE *node_get_next(NODE *node);
#endif 