#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  list_t *list = list_alloc(7);
  
  list_add_to_front(list, 9);
  
  list_print(list);
	printf("--------------------------------------\n");
  
  list_add_to_back(list, 10);
	list_add_to_back(list, 23);
  
  list_print(list);
	printf("--------------------------------------\n");
	
	list_remove_from_back(list);
	
	list_print(list);
	printf("--------------------------------------\n");
	
	list_remove_from_front(list);
	
	list_print(list);
	printf("--------------------------------------\n");
	
	list_add_to_back(list, 667);
	list_add_to_back(list, 1960);
	list_add_to_back(list, 123);
	list_add_to_back(list, 90);
	
	list_print(list);
	printf("--------------------------------------\n");
	
	printf("Element at 3: %d\n",list_get_elem_at(list, 3));
	printf("Index of 1960: %d\n",list_get_index_of(list, 1960));
	printf("Is 1960 in the list? %d\n",list_is_in(list, 1960));
  
  return 0;
}
