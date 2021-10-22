#ifndef DISTANCE_LIST_NODE_H
	#define DISTANCE_LIST_NODE_H
	#include <stdbool.h>

	typedef struct distance_list_node_ DISTANCE_LIST_NODE ;

	int distance_list_node_get_key(DISTANCE_LIST_NODE  *distance_list_node);
	int distance_list_node_get_from(DISTANCE_LIST_NODE  *distance_list_node);
	int distance_list_node_get_to(DISTANCE_LIST_NODE  *distance_list_node);
	int distance_list_node_get_distance(DISTANCE_LIST_NODE  *distance_list_node);

	bool distance_list_node_free(DISTANCE_LIST_NODE  **distance_list_node);
	bool distance_list_node_set_key(DISTANCE_LIST_NODE  *distance_list_node, int key);
	bool distance_list_node_set_from(DISTANCE_LIST_NODE  *distance_list_node, int from);
	bool distance_list_node_set_to(DISTANCE_LIST_NODE  *distance_list_node, int to);
	bool distance_list_node_set_distance(DISTANCE_LIST_NODE  *distance_list_node, int distance);
	bool distance_list_node_set_next(DISTANCE_LIST_NODE  *distance_list_node, DISTANCE_LIST_NODE  *next);
	bool distance_list_node_set_prev(DISTANCE_LIST_NODE  *distance_list_node, DISTANCE_LIST_NODE  *prev);
	bool distance_list_node_delete_key(DISTANCE_LIST_NODE  **distance_list_node);//adicionei
	
	void distance_list_node_print(DISTANCE_LIST_NODE  *distance_list_node);

	DISTANCE_LIST_NODE  *distance_list_node_create(int key);
	DISTANCE_LIST_NODE  *distance_list_node_get_prev(DISTANCE_LIST_NODE  *distance_list_node);
	DISTANCE_LIST_NODE  *distance_list_node_get_next(DISTANCE_LIST_NODE  *distance_list_node);
#endif 