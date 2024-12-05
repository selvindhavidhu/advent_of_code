#include "int_list.h"

void int_list_init(struct int_list *list)
{
	if (list) {
		list->head = NULL;
		list->size = 0;
	}
}

void int_list_free(struct int_list *list)
{
	if (list) {
		struct nodei *current_node = list->head;
		while (current_node) {
			struct nodei *next = current_node->next;
			free(current_node);
			current_node = next;
		}

		list->head = NULL;
		list->size = 0;
	}
}

void int_list_push_back(struct int_list *list, int value)
{
	if (!list)
		return;

	struct nodei *new_node = (struct nodei *)malloc(sizeof(struct nodei));
	if (!new_node) {
		fprintf(stderr, "Insufficient memory.\n");
		exit(ENOMEM);
	}

	new_node->value = value;
	new_node->next = NULL;

	++(list->size);
	if (!list->head) {
		list->head = new_node;
		return;
	}

	struct nodei *current = list->head;
	while (current) {
		if (!current->next) {
			current->next = new_node;
			return;
		}
		current = current->next;
	}
}

void int_list_copy_into(struct int_list *list, int *buffer)
{
	if (!list)
		return;

	struct nodei *p = list->head;
	for (int i = 0; p && (i < list->size); ++i) {
		buffer[i] = p->value;
		p = p->next;
	}
}

void int_list_for_each(struct int_list *list, void (*callback_fn)(int))
{
	if (!list)
		return;

	struct nodei *p = list->head;
	while (p) {
		callback_fn(p->value);
		p = p->next;
	}
}