#include "int_vector.h"

static const int INITIAL_CAPACITY = 5;
static const float SCALE_FACTOR = 1.5f;

static void ensure_capacity(struct int_vector *v, int min_capacity)
{
	if (!v || (min_capacity < 1) || (min_capacity < v->capacity))
		return;

	int new_capacity = (int)((float)v->capacity * SCALE_FACTOR);
	size_t nbytes = sizeof(int) * new_capacity;
	int *p = realloc(v->elements, nbytes);
	if (!p) {
		fprintf(stderr, "Failed to allocate %zu bytes of memory.\n",
			nbytes);
		int_vector_free(v);
		exit(ENOMEM);
	}

	v->elements = p;
	v->capacity = new_capacity;
}

static void check_index(struct int_vector *v, int index)
{
	if (v) {
		if (index < 0) {
			fprintf(stderr, "Error: index '%d' can't be negative.\n",
				index);
			exit(EINVAL);
		}

		if (int_vector_is_empty(v)) {
			fprintf(stderr, "Error: index '%d' is invalid because the vecor is empty.\n", index);
			exit(EINVAL);
		}

		if (index >= v->size) {
			fprintf(stderr,
				"Error: index '%d' can't be greater than or equal to the size of the vector (%d).\n",
				index, v->size);
			exit(EINVAL);
		}
	}
}

void int_vector_init(struct int_vector *v)
{
	if (v) {
		v->size = 0;
		v->capacity = INITIAL_CAPACITY;

		size_t nbytes = sizeof(int) * INITIAL_CAPACITY;
		v->elements = (int *)malloc(nbytes);
		if (!v->elements) {
			fprintf(stderr, "Failed to allocate %zu bytes of memory.\n", nbytes);
			exit(ENOMEM);
		}
		memset(v->elements, 0, nbytes);
		
	}
}

void int_vector_free(struct int_vector *v)
{
	if (v) {
		v->size = 0;
		v->capacity = 0;
		if (v->elements) {
			free(v->elements);
			v->elements = NULL;
		}
	}
}

int int_vector_get_size(struct int_vector *v)
{
	return v ? v->size : 0;
}

int int_vector_is_empty(struct int_vector *v)
{
	return v ? (v->size == 0) : 1;
}

void int_vector_push_back(struct int_vector *v, int value)
{
	ensure_capacity(v, v->size + 1);
	v->elements[v->size] = value;
	++(v->size);
}

void int_vector_push_front(struct int_vector *v, int value)
{
	ensure_capacity(v, v->size + 1);
	if (v->size > 0) {
		//int last = v->elements[v->size - 1];
		memmove(v->elements + 1, v->elements,
			(v->size - 1) * sizeof(int));
		//v->elements[0] = last;
	}

	v->elements[0] = value;
	++(v->size);
}

void int_vector_add(struct int_vector *v, int value, int index)
{
}

int int_vector_remove(struct int_vector *v, int index)
{
	return 0;
}

int int_vector_get(struct int_vector *v, int index)
{
	check_index(v, index);
	return v->elements[index];
}

int int_vector_get_first(struct int_vector *v)
{
	check_index(v, 0);
	return v->elements[0];
}

int int_vector_get_last(struct int_vector *v)
{
	check_index(v, v->size - 1);
	return v->elements[v->size - 1];
}

void int_vector_for_each(struct int_vector *v, void (*callback_fn)(int))
{
}