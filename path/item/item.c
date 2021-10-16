#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "item.h"

struct item_{ 
    int key;
};

ITEM *item_create (int key){
          ITEM *item;
          
          item = (ITEM *) malloc(sizeof(ITEM));
          
          if (item != NULL){
             item->key = key;
             return(item);
          }
          return(NULL);
}

bool item_free(ITEM **item){
   if (*item != NULL){
      free (*item);
      *item = NULL; 
      return(true);
   }
   return(false);
}

int item_get_key(ITEM *item){
    if (item != NULL)
      return(item->key);
    exit(1);
}


bool item_set_key(ITEM *item, int key){
  if (item != NULL){
    item->key = key;
    return (true);
  }
  return (false);
}

void item_print(ITEM *item){
     if (item != NULL)
        printf("\n-->item: %d\n", item->key);
}