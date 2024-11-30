#include "day_1.h"

#define MAX_LINE_SIZE 512

int solve_day_1(const char *input_file_path)
{
	FILE *fp = fopen(input_file_path, "r");
	if (fp == NULL) {
		fprintf(stderr, "Failed to open file: %s for reading.\n",
			input_file_path);
		exit(ENOENT);
	}

	int sum = 0;
	char line[MAX_LINE_SIZE + 1] = { 0 };
	int num[2] = { 0, 0 };

	while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
		int line_length = (int)strlen(line);

		/* Find the first digit. */
		for (int i = 0; i < line_length; ++i) {
			int ch = line[i];
			if (isdigit(ch)) {
				num[0] = ch - '0';
				break;
			}
		}

		/* Find the second digit. */
		for (int j = line_length - 1; j >= 0; --j) {
			int ch = line[j];
			if (isdigit(ch)) {
				num[1] = ch - '0';
				break;
			}
		}

		sum += (num[0] * 10) + num[1];
		memset(line, 0, MAX_LINE_SIZE + 1);
	}

	fclose(fp);

	return sum;
}

int solve_day_1_part_2(const char *input_file_path)
{
	FILE *fp = fopen(input_file_path, "r");
	if (fp == NULL) {
		fprintf(stderr, "Failed to open file: %s for reading.\n",
			input_file_path);
		exit(ENOENT);
	}

	const char words[9][6] = { "one", "two",   "three", "four", "five",
				   "six", "seven", "eight", "nine" };

	const int words_length[9] = {3, 3, 5, 4, 4, 3, 5, 5, 4};
	int sum = 0;
	char line[MAX_LINE_SIZE + 1] = { 0 };
	int num[2] = { 0, 0 };

	while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
		int line_length = (int)strlen(line);

		/* Find the first digit. */
		for (int i = 0; i < line_length; ++i) {
			int ch = line[i];
			if (isdigit(ch)) {
				num[0] = ch - '0';
				break;
			} else {
				
			}
		}

		/* Find the second digit. */
		for (int j = line_length - 1; j >= 0; --j) {
			int ch = line[j];
			if (isdigit(ch)) {
				num[1] = ch - '0';
				break;
			}
		}

		sum += (num[0] * 10) + num[1];
		memset(line, 0, MAX_LINE_SIZE + 1);
	}

	fclose(fp);
	return sum;
}