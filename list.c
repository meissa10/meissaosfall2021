// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_t *list_alloc(elem val) {
  list_t *l = malloc(sizeof(list_t));
  l->head = malloc(sizeof(node_t));
  l->head->value = val;
  return l;
 }

void list_free(list_t *l) {
  node_t *t = l->head;
    while(t){
      node_t *temp = t;
      t = t->next;
      free(temp);
    }
    free(t);
    return; 
    }

void list_print(list_t *l){   
  node_t *t = l->head;
  while (t){
    printf("%d \n", t->value);
    t = t->next;
  }
}

int list_length(list_t *l) { 
  if(!l->head || !l){
    return 0;
  }
  int length = 1;
  node_t *t = l->head;
  
	while(t){
    length++;
    t = t->next;
	}
	printf("Length: %d \n", length);
  return length; 
}

void list_add_to_back(list_t *l, elem value) {
	if(!l){
		printf("This list does not exist.");
		return;
	}
  node_t *t = l->head;
  list_t *n = list_alloc(value);
  while(t->next != NULL){
    t = t->next;
  }
  t->next = n->head;
}

void list_add_to_front(list_t *l, elem value) {
	if(!l){
		printf("This list does not exist.");
		return;
	}
  list_t *n = list_alloc(value);
  node_t *t = l->head;
	n->head->next = t;
	l->head = n->head;
}

void list_add_at_index(list_t *l, elem value, int index) {
  if(!l){
		printf("This list does not exist.");
		return;
	}
	list_t *n = list_alloc(value);
	int i = 0;
	node_t *t = l->head;
	while(t->next != NULL && i != index){
		t = t->next;
		i++;
	}
	n->head->next = t;
	t = n->head;
  }


elem list_remove_from_back(list_t *l) {
	if(!l){
		return;
	}
	node_t *t = l->head;
	while(t->next->next != NULL){
		t = t->next;
	}
	elem to_r = t->value;
	free(t->next);
  t-> next = NULL;
	return to_r;
}

elem list_remove_from_front(list_t *l) { 
	if(!l){
		printf("This list does not exist.");
		return;
	}
	elem to_r = l->head->value;
	node_t *front = l->head;
	l->head = l->head->next;
	free(front);
	return to_r;
}

elem list_remove_at_index(list_t *l, int index) {
  if(!l){
		printf("This list does not exist.");
		return;
	}
	int i = 0;
	node_t *t = l->head;
	while(t->next != NULL && i < index){
		t = t->next;
		i++;
	}
	node_t *to_r = t->next;
	elem val = t->next->value;
	t->next = t->next->next;
	free(to_r);
	return val;
}

bool list_is_in(list_t *l, elem value) {
  if(!l){
		printf("This list does not exist.");
		return;
	}
	node_t *t = l->head;
	while(t->next){
    if (t->value==value){
      return true;
    }
		t = t->next;
	}
	return t->value == value;
}

elem list_get_elem_at(list_t *l, int index) { 
  if(!l){
		printf("This list does not exist.");
		return;
	}
	int i = 0;
	node_t *t = l->head;
	while(t->next != NULL && i < index){
		t = t->next;
		i++;
	}
	return t->value;
}

int list_get_index_of(list_t *l, elem value) { 
	 if(!l){
		printf("This list does not exist.");
		return;
	}
	int i = 0;
	node_t *t = l->head;
	elem to_r = t->value;
	while(to_r != value && t->next){
		t = t->next;
    if(t->value == value){
		return i+1;
    }
		i++;
	}
	
	printf("Value not in the list\n");
	return 0;
}

