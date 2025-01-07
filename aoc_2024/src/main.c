#include "day_1/day_1.h"
#include "int_vector.h"
#include "stdheaders.h"

void printi(int value)
{
    printf("%d\t", value);
}

int main(void)
{
	struct int_vector v;

    int_vector_init(&v);
	for (int i = 0; i < 20; ++i) {
	    int_vector_push_back(&v, (i + 1));
	}

	size_t len = int_vector_get_size(&v);
	for (size_t i = 0; i < len; ++i) {
		printf("%d\t", v.elements[i]);
	}
	printf("\n");

	int_vector_free(&v);

    //const char input_file_path[] = "2024_day_1_sample_input_part_2.txt";
    //printf("output: %d\n", solve_day_1_part_1(input_file_path));

    return EXIT_SUCCESS;
}