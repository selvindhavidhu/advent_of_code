#ifndef SELVIN_AOC_INT_VECTOR_H_
#define SELVIN_AOC_INT_VECTOR_H_

#include "stdheaders.h"

struct int_vector {
	int *elements;
	int size;
	int capacity;
};

void int_vector_init(struct int_vector *v);
void int_vector_free(struct int_vector *v);

int int_vector_get_size(struct int_vector *v);
int int_vector_is_empty(struct int_vector *v);

void int_vector_push_back(struct int_vector *v, int value);
void int_vector_push_front(struct int_vector *v, int value);
void int_vector_add(struct int_vector *v, int value, int index);
int int_vector_remove(struct int_vector *v, int index);

int int_vector_get(struct int_vector *v, int index);
int int_vector_get_first(struct int_vector *v);
int int_vector_get_last(struct int_vector *v);
void int_vector_for_each(struct int_vector *v, void (*callback_fn)(int));

#endif