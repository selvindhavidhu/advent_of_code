#include "day_1.h"
#include "../int_list.h"
#include "../fileop.h"

// Comparison function for integers
static int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

static void parse_input_into_lists(const char *buffer,
				   struct int_list *left_list,
				   struct int_list *right_list)
{
	char *line = strtok(buffer, "\n");
	int n1 = 0, n2 = 0;
	while (line != NULL) {
		(void)sscanf(line, "%d %d", &n1, &n2);
		int_list_push_back(left_list, n1);
		int_list_push_back(right_list, n2);
		line = strtok(NULL, "\n");
	}
}



int solve_day_1_part_1(const char *input_file_path)
{
	size_t file_size = get_file_size(input_file_path) + 1;
	char *buffer = (char *)malloc(sizeof(char) * file_size);
	if (!buffer) {
		fprintf(stderr, "Insufficient memory.\n");
		exit(ENOMEM);
    }
	memset(buffer, 0, file_size);
	read_file_contents(input_file_path, buffer, file_size);
	
    struct int_list left_list = { 0 };
	struct int_list right_list = { 0 };
    parse_input_into_lists(buffer, &left_list, &right_list);

	int *left_array = (int *)malloc(sizeof(int) * left_list.size);
    int *right_array = (int *)malloc(sizeof(int) * right_list.size);

	int_list_copy_into(&left_list, left_array);
    int_list_copy_into(&right_list, right_array);

	qsort(left_array, left_list.size, sizeof(int), compare);
    qsort(right_array, right_list.size, sizeof(int), compare);

	int sum = 0;
    int distance = 0;
	for (int i = 0; i < left_list.size; ++i) {
	    distance = abs(left_array[i] - right_array[i]);
		sum += distance;
	}

	free(buffer);
    free(left_array);
	free(right_array);
    int_list_free(&left_list);
	int_list_free(&right_list);
    
    return sum;
}

int solve_day_1_part_2(const char *input_file_path)
{
    FILE *fp = fopen(input_file_path, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open file: %s for reading.\n", input_file_path);
        exit(ENOENT);
    }

    int sum = 0;

    fclose(fp);
    return sum;
}