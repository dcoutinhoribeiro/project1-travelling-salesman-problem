#ifndef ITEM_H
	#define ITEM_H

	#define TRUE 1 /*define valor booleano  não existe na linguagem C*/
	#define FALSE 0
	#define boolean int /*define um tipo booleano*/
	#define ERRO -32000

	#include <stdbool.h>

	typedef struct item_ ITEM;

	ITEM *item_create(int chave);
	bool item_free(ITEM **item);
	void item_print(ITEM *item);
	int item_get_key(ITEM *item);
	bool item_set_key(ITEM *item, int chave);

#endif