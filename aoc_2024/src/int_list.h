#ifndef SELVIN_AOC_INT_LIST_H_
#define SELVIN_AOC_INT_LIST_H_

#include "stdheaders.h"

struct nodei {
	int value;
	struct nodei *next;
};

struct int_list {
	struct nodei *head;
	int size;
};

void int_list_init(struct int_list *list);
void int_list_free(struct int_list *list);

void int_list_push_back(struct int_list *list, int value);
void int_list_copy_into(struct int_list *list, int *buffer);
void int_list_for_each(struct int_list *list, void (*callback_fn)(int));

#endif