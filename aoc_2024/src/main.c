#include "day_1/day_1.h"
#include "stdheaders.h"
#include "int_list.h"

void printi(int value)
{
	printf("%d\t", value);
}

int main(void)
{
    const char input_file_path[] = "2024_day_1_sample_input_part_2.txt";
    printf("output: %d\n", solve_day_1_part_1(input_file_path));

    return EXIT_SUCCESS;
}